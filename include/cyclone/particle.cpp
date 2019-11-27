#include <assert.h>
#include <cyclone/particle.h>

using namespace cyclone;

void Particle::integrate(real duration)
{
   //we don't integrate things with infinite mass
   if(inverse_mass <= 0.0f) return;

   assert(duration > 0.0);

   //update linear position
   position.add_scaled_vector(velocity, duration);

   /*
   work out the acceleration from the force (we'll add
   to this vector when we come to generate force)
   */
   Vector3 resulting_acc = acceleration;

   //update linear velocity from the acceleration
   velocity.add_scaled_vector(resulting_acc, duration);

   //impose drag
   velocity *= real_pow(damping, duration);

   clear_accumulator();

}