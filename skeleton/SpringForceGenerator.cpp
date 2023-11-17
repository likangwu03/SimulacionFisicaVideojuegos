#include "SpringForceGenerator.h"


SpringForceGenerator::SpringForceGenerator(double k, double resting_length, Particle* other):_k(k),_resting_length(resting_length),_other(other) {

}
void SpringForceGenerator::updateForce(Particle* particle, double t) {

}