#include <iostream>
#include "body.h"
using namespace std;

Body::Body(int numHeads, int numArms, int numLegs) {
    heads = numHeads;
    arms = numArms;
    legs = numLegs;
}

void Body::setHeads(int numHeads) {
    heads = numHeads;
}

void Body::setArms(int numArms) {
    heads = numArms;
}

void Body::setLegs(int numLegs) {
    heads = numLegs;
}

int Body::getHeads() {
    return heads;
}

int Body::getArms() {
    return arms;
}

int Body::getLegs() {
    return legs;
}

int main() {
    Body human(1, 2, 2);
    cout << "Specimen has " << human.getArms() << " arms, " << human.getLegs() << " legs, and " << human.getHeads() << " heads." << endl;
}