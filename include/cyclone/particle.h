/* 
aparticle is the simplist object that can be simulated in
the physics system.
*/
namespace cyclone {

   class Particle
   {
      protected:
         /*
         holds the linear position of the particle in the 
         world space.
         */

         Vector3 position;

         /* holds the linear velocity of the particle in 
         world space.
         */

         Vector3 velocity;

         /*
         holds the acceleration of the particle. this value 
         can be used to set acceleration due to gravity (its primary 
         use), or any other constant acceleration.
         */

         Vector3 acceleration;


         /*
         holds the amount of damping applied to linear motion. 
         damping is required to remove energy added through 
         numerical instability in the integrator.  
         */
         real damping; //0 full drag - 1 no drag, but should use .999

         /*
         holds the inverse of the mass of the particle. It is more 
         useful to hold the inverse of the mass because integration 
         is simpler, and because in real-time simulation it is more 
         useful to have objects with infinite mass (immovable) than
         zero mass (completely unstable in numerical simulation)
         */

         real inverse_mass;

      public:

         /*
         sets the value for inverse mass
         */
         
         set_inverse_mass(const real value) 
         {
            inverse_mass = value;
         }

         /*
         sets the value for inverse mass based on mass
         */
         
         set_mass(const real value) 
         {
            if (value == 0) { return; }//throw error 
            inverse_mass = 1/value;
         }

         /*
         integrates the particle forward in time by the given 
         amount. this function uses a Newton-Euler integration
         method, which is linear approximation to the correct 
         integral. for this reason it may be inaccurate in some
         cases.
         */
         void integrate(real duration);
   }; 

namespace cyclone {