#define setEngTemp(octet)   octet |= (1 << 0);
#define setCarWt(octet)     octet |= (1 << 1);
#define setRPM(octet)       octet |= (1 << 2);
#define setFuel(octet)      octet |= (1 << 3);
#define setSusp(octet)      octet |= (1 << 4);