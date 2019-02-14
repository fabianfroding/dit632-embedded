# include <stdio.h>

int main(void) {
    unsigned int i = 0;

    int engine_on = 1;
    int gear_pos =2;
    int key_pos = 2;
    int brake1 = 1;
    int brake2 = 1;

    i |= s1.brake2;
    i |= (s1.brake1 << 1);
    i |= (s1.key_pos << 2);
    i |= (s1.gear_pos << 4);
    i |= (s1.engine_on << 7);

    return 0;
}