// This example has a main subscriber that will subscriber to several topics
// Topics will be:
//  - RPMData
//  - EngineTemperature
//  - FuelStatus
//  - CarWeight
//  - SuspensionStatus
// main subscriber will get data from all these publishers and will give status of the car

##Modifications:
 - 1 subscriber will listen to all 5, if it gets 2 then it will print those 2
 - 2nd subscriber will listen to only specific 2 out of 5 and will print their status
 - 3rd will listen to remaining 3 out of 5 and will print their status

##Note:
 - The code should be dynamic and separated into functional units