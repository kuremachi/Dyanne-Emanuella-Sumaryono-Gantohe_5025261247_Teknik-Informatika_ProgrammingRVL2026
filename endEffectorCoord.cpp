/*  Dyanne Emanuella Sumaryono Gantohe
    NRP 5025261247

    RIVAL Internship Phase - End Effector Calculator
*/

#include <iostream>
#include <cmath>
#define PI 3.1415926535
using namespace std;

double COORDx(double armLength, double angle, double xCoord){
    double rad = angle * (PI / 180);
    xCoord = armLength * cos(rad);
    return xCoord;
}

double COORDy(double armLength, double angle, double yCoord){
    double rad = angle * (PI / 180);
    yCoord = armLength * sin(rad);
    return yCoord;
}

int main() {
    double L{}, angle{}, x{}, y{};

    int DOF{};
    cout<< "Insert Degree of Freedom: ";
    cin >> DOF;

    if (DOF < 1){
        cout<< "[ERROR: Invalid Degree of Freedom!]" << endl;
    }

    for(int i = 1; i <= DOF; i++){
        double newAngle{};

        cout<< "\n>> LINK No. " << i << endl;
        cout<< "Arm Length of Link " << i << "     : ";
        cin >> L;
        cout<< "Angle of Link " << i << " (degrees): ";
        cin >> newAngle;

        angle += newAngle;
        x += COORDx(L, angle, x);
        y += COORDy(L, angle, y);

        cout<< "-> Current End Coordinates (x, y): " << x << ", " << y << endl;
    }

    if (DOF >= 1){
        cout<< "\n>> Coordinates of End Effector: " << x << ", " << y;
    }
}