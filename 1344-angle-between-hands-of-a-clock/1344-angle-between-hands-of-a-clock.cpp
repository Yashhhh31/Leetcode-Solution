class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = 6.0 * minutes;
        double hourAngle = 30.0 * (hour % 12) + 0.5 * minutes;

        double diff = abs(minuteAngle - hourAngle);
        diff = min(diff, 360.0 - diff);

        return diff;

    }
};