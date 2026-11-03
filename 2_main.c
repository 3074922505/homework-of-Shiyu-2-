//202610302223
//王诗喻

#include <stdio.h>

struct Sensor {
    int temp;
    int humi;
    int valid;
};

struct Sensor pack_sensor(int t, int h) {
    struct Sensor result;

    result.temp = t;
    result.humi = h;

    if (t >= -20 && t <= 50 && h >= 0 && h <= 100) {
        result.valid = 1;
    } else {
        result.valid = 0;
    }

    return result;
}

int main(void) {
    int t, h;
    struct Sensor sensor;

    if (scanf("%d%d", &t, &h) != 2) {
        return 0;
    }

    sensor = pack_sensor(t, h);

    if (sensor.valid) {
        printf("TEMP=%d HUMI=%d\n", sensor.temp, sensor.humi);
    } else {
        printf("ERROR: Out of Range\n");
    }

    return 0;
}
