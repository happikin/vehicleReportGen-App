/*
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include <ace/Log_Msg.h>
#include <ace/OS_NS_stdlib.h>

#include "DataReaderListenerImpl.h"
#include "StatusTypeSupportC.h"
#include "StatusTypeSupportImpl.h"

#include <iostream>

StatusData statusData;
std::mutex mutex;

#define engTempIsSet(octet) (octet & (1 << 0))
#define carWtIsSet(octet) (octet & (1 << 1))
#define rpmIsSet(octet) (octet & (1 << 2))
#define fuelIsSet(octet) (octet & (1 << 3))
#define suspIsSet(octet) (octet & (1 << 4))

void
DataReaderListenerImpl::on_requested_deadline_missed(
  DDS::DataReader_ptr /*reader*/,
  const DDS::RequestedDeadlineMissedStatus& /*status*/)
{
}

void
DataReaderListenerImpl::on_requested_incompatible_qos(
  DDS::DataReader_ptr /*reader*/,
  const DDS::RequestedIncompatibleQosStatus& /*status*/)
{
}

void
DataReaderListenerImpl::on_sample_rejected(
  DDS::DataReader_ptr /*reader*/,
  const DDS::SampleRejectedStatus& /*status*/)
{
}

void
DataReaderListenerImpl::on_liveliness_changed(
  DDS::DataReader_ptr /*reader*/,
  const DDS::LivelinessChangedStatus& /*status*/)
{
}

void
DataReaderListenerImpl::on_data_available(DDS::DataReader_ptr reader)
{
  StatusDataReader_var reader_i =
    StatusDataReader::_narrow(reader);

  if (!reader_i) {
    ACE_ERROR((LM_ERROR,
               ACE_TEXT("ERROR: %N:%l: on_data_available() -")
               ACE_TEXT(" _narrow failed!\n")));
    ACE_OS::exit(1);
  }

  Status message;
  DDS::SampleInfo info;

  const DDS::ReturnCode_t error = reader_i->take_next_sample(message, info);

  if (error == DDS::RETCODE_OK) {
    // std::cout << "SampleInfo.sample_rank = " << info.sample_rank << std::endl;
    // std::cout << "SampleInfo.instance_state = " << OpenDDS::DCPS::InstanceState::instance_state_mask_string(info.instance_state) << std::endl;

    if (info.valid_data) {
      std::string type;
      
      if(engTempIsSet(message.ready)) {
        statusData.setEngT(message.engineTemp);
        type = "Engine Temperature";
        //std::cout << "Engine Temperature: " << message.engineTemp << std::endl;
      }
      if(carWtIsSet(message.ready)) {
        statusData.setCarW(message.carWeight);
        type = "Car Weight";
        //std::cout << "Car Weight: " << message.carWeight << std::endl;
      }
      if(rpmIsSet(message.ready)) {
        statusData.setRMPStatus(message.rpmStatus);
        type = "RPM";
        //std::cout << "RPM: " << message.rpmStatus << std::endl;
      }
      if(fuelIsSet(message.ready)) {
        statusData.setFuelStatus(message.fuelTank);
        type = "Fuel Status";
        //std::cout << "Fuel: " << message.fuelTank << std::endl;
      }
      if(suspIsSet(message.ready)) {
        statusData.setSuspHealth(message.suspensionHealth);
        type = "Suspension Health";
        //std::cout << "Suspension Health: " << message.suspensionHealth << std::endl;
      }
      //std::cout << "MESSAGE::Received payload " << type << std::endl;
      std::cout << "#";
    }

  } else {
    ACE_ERROR((LM_ERROR,
               ACE_TEXT("ERROR: %N:%l: on_data_available() -")
               ACE_TEXT(" take_next_sample failed!\n")));
  }
}

void
DataReaderListenerImpl::on_subscription_matched(
  DDS::DataReader_ptr reader,
  const DDS::SubscriptionMatchedStatus& status)
{
}

void
DataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr /*reader*/,
  const DDS::SampleLostStatus& /*status*/)
{
}

void StatusData::setEngT(CORBA::Float& val) {
  setEngTemp(flags);
  reinterpret_cast<Status*>(data)->engineTemp = val;
  dumpclear();
}
void StatusData::setCarW(CORBA::Float& val) {
  setCarWt(flags);
  reinterpret_cast<Status*>(data)->carWeight = val;
  dumpclear();
}
void StatusData::setRMPStatus(CORBA::Long& val) {
  setRPM(flags);
  reinterpret_cast<Status*>(data)->rpmStatus = val;
  dumpclear();
}
void StatusData::setFuelStatus(CORBA::Float& val) {
  setFuel(flags);
  reinterpret_cast<Status*>(data)->fuelTank = val;
  dumpclear();
}
void StatusData::setSuspHealth(CORBA::Float& val) {
  setSusp(flags);
  reinterpret_cast<Status*>(data)->suspensionHealth = val;
  dumpclear();
}

void StatusData::dumpclear() {
  if((flags & (0xFF)) == (0xFF)) {
    // --------We can process the Vehicle status-------- //

    Status* status = new Status;
    
    status->carWeight         = reinterpret_cast<Status*>(data)->carWeight;
    status->engineTemp        = reinterpret_cast<Status*>(data)->engineTemp;
    status->rpmStatus         = reinterpret_cast<Status*>(data)->rpmStatus;
    status->fuelTank          = reinterpret_cast<Status*>(data)->fuelTank;
    status->suspensionHealth  = reinterpret_cast<Status*>(data)->suspensionHealth;
    
    buffer.push(status);
    status = nullptr;

    flags = 0b11100000;
    //exit(1);
  }
}

void StatusData::allocMem() {
  this->data =  malloc(sizeof(Status));
  spitter = new std::thread(std::bind(&StatusData::DisplayFunc,this));
}

void StatusData::deallocMem() {
  free(this->data);
  mRunning = false;
  delete spitter;
}

int StatusData::DisplayFunc() {
  std::mutex mutex;
// Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Vehicle Test Report Application", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();
    // ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    static std::queue<Status> locBuffer;

    std::thread getter([&](){
      while(mRunning) {
        while(!this->buffer.empty() && (data != nullptr)) {
          // Instead of logging data here in the console, build the graph in GUI
          // std::cout << "\n------------Vehicle Report------------\n";
          // std::cout << "Engine Temperature  : " << reinterpret_cast<Status*>(buffer.front())->engineTemp << "^C" << std::endl;
          // std::cout << "Car Weight          : " << reinterpret_cast<Status*>(buffer.front())->carWeight << "Kg" << std::endl;
          // std::cout << "RPM Status          : " << reinterpret_cast<Status*>(buffer.front())->rpmStatus << " RPM" << std::endl;
          // std::cout << "Fuel Tank           : " << reinterpret_cast<Status*>(buffer.front())->fuelTank << "%" << std::endl;
          // std::cout << "Suspension Health   : " << reinterpret_cast<Status*>(buffer.front())->suspensionHealth << "% health" << std::endl;
          // std::cout << "--------------------------------------\n";
          
          locBuffer.push(*reinterpret_cast<Status*>(buffer.front()));

          buffer.pop();
        }
      }
    });
    // Main loop
    while (!glfwWindowShouldClose(window) && mRunning)
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::BulletText("-X-X-X-X- Vehicle Status Report -X-X-X-X-");
        ImGui::BulletText("This example assumes 60 FPS. Higher FPS requires larger buffer size.");

        //static ScrollingBuffer sdataX, sdataY;
        static RollingBuffer   rpmData;
        static RollingBuffer   engineData;
        RollingBuffer   fuelData;
        static RollingBuffer susData;
        static RollingBuffer wtData;

        Status status = locBuffer.front();
        if(locBuffer.size() > 1) {
          locBuffer.pop();
        }

        static float t = 0;
        t += ImGui::GetIO().DeltaTime;

        rpmData.AddPoint(t,status.rpmStatus * 0.0005f);
        engineData.AddPoint(t,status.engineTemp * 0.0005f);
        susData.AddPoint(t,status.suspensionHealth * 0.0005f);
        wtData.AddPoint(t,status.carWeight * 0.0010f);
        float bar_data[1]{(float)status.fuelTank * 0.01f};

        static float history = 10.0f;
        ImGui::SliderFloat("History",&history,1,30,"%.1f s");
        rpmData.Span = history;

        static ImPlotAxisFlags flags = ImPlotAxisFlags_NoTickLabels;

        if (ImPlot::BeginPlot("##RPM", ImVec2(-1,200))) {
            ImPlot::SetupAxes(NULL, NULL, flags, flags);
            ImPlot::SetupAxisLimits(ImAxis_X1,0,history, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1,0,1);
            ImPlot::PlotLine("RPM Value", &rpmData.Data[0].x, &rpmData.Data[0].y, rpmData.Data.size(), 0, 2 * sizeof(float));
            ImPlot::EndPlot();
        }

        if (ImPlot::BeginPlot("##ENGINE", ImVec2(-1,200))) {
            ImPlot::SetupAxes(NULL, NULL, flags, flags);
            ImPlot::SetupAxisLimits(ImAxis_X1,0,history, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1,0,1);
            ImPlot::PlotLine("Engine Temperature", &engineData.Data[0].x, &engineData.Data[0].y, engineData.Data.size(), 0, 2 * sizeof(float));
            ImPlot::EndPlot();
        }


        if(ImPlot::BeginPlot("##FUEL",ImVec2(-1,150))) {
            ImPlot::PlotBarsH("Fuel Status", bar_data, 1,50.0f);
            ImPlot::EndPlot();
        }
        
        if(ImPlot::BeginPlot("##Suspension&Weight", ImVec2(-1,150))) {
            ImPlot::SetupAxes(NULL, NULL, flags, flags);
            ImPlot::SetupAxisLimits(ImAxis_X1,0,history, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1,0,1);
            ImPlot::PlotLine("Suspension Health", &susData.Data[0].x, &susData.Data[0].y, susData.Data.size(), 0, 2 * sizeof(float));
            ImPlot::PlotLine("Car Weight", &wtData.Data[0].x, &wtData.Data[0].y, wtData.Data.size(), 0, 2 * sizeof(float));
            ImPlot::EndPlot();
        }

        // Rendering
        
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    ImPlot::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;

}