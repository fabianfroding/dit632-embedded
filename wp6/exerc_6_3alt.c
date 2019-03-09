#define ML13_Status 0x0B00
#define ML13_Control 0x0B00
#define REG8(x) *((unsigned char *)(x)) // A macro to use for IO R/W
#define open_door 0x01
#define close_door 0x02
#define thirtySeconds 30000

int main()
{
    while (1)
    {
        if (REG8(ML13_Status) | 3)
        { //if any of the sensors are triggered
            REG8(ML13_Control) = open_door;
            /*
            control doors closing and opening
            */
        }
    }
}