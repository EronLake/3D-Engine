//Eron's 3D Engine 
//#include "percision.h"


namespace cyclone {
   /*
   holds a vector ub three dimentions. four data members are allocated
   to ensure the allignment in an array.
   */  

   class Vector3
   {
      public:
         /* holds vectors along the x axis */
         real X;
         /* holds vectors along the x axis */
         real Y;
         /* holds vectors along the x axis */
         real Z;
      
      private:
         /* padding to ensure 4-word alignment */
         real pad;

      public:
         /* the default constructor takes a zero vector. */
         Vector3() : x(0), y(0), z(0) {}

         /* flips all the components of the vector, */
         void invert()
         {
            X = -X;
            Y = -Y;
            Z = -Z;
         }

         /* gets the magnitude of this vector. */ 
         real magnitude() const /* this const refers to "this" */
         {
            return real_sqrt(X*X + Y*Y + Z*Z);
         }

         /* gets the squared magnitude of this vector. */
         real squared_magnitude() const
         {
            return  X*X + Y*Y + Z*Z;
         }     

         /* turns and non-zero verctor into a unit length vector. */
         void normalize()
         {
            real len = magnitude();
            if(len > 0)
            {
               (*this) *= ((real)1)/len;
            }

         }

         ///////////////////////////////////////////////////////////
         //scalar multiplication

         /* multiplies this vector by the given scalar. */
         void operator*=(const real value)
         {
            X *= value;
            Y *= value;
            Z *= value;
         }

         /* returns a copy of this vector scaled by the given value. */
         Vector3 operator*(const real value) const
         {
            return Vector3(X*value, Y*value, Z*value); 
         }
         

         ///////////////////////////////////////////////////////////
         //addition and subtraction

         /* adds the given vector to this. */         
         void operator+=(const Vector3& vec)
         {
            X += vec.X;
            Y += vec.Y;
            Z += vec.Z;

         }

         /*returns the value of the given vector added to this */
         Vector3 operator+(const Vector3& vec) const
         {
            return Vector3(X+vec.X, Y+vec.Y, Z+vec.Z);
         }

          /* adds the given vector to this. */         
         void operator-=(const Vector3& vec)
         {
            X -= vec.X;
            Y -= vec.Y;
            Z -= vec.Z;

         }

         /*returns the value of the given vector subtracted to this. */
         Vector3 operator-(const Vector3& vec) const
         {
            return Vector3(X-vec.X, Y-vec.Y, Z-vec.Z);
         }

         /* adds the given vector to this, scaled by the given amount. */
         void add_scaled_vector(const Vector3& vec, const real scalar)
         {
            X += vec.X * scalar;
            Y += vec.Y * scalar;
            Z += vec.Z * scalar;
         }

         ///////////////////////////////////////////////////////////
         // vector multiplication

         /* calculates annd returns a component-wise product of this 
         vector with the given vector */
         Vector3 component_product(const Vector3& vec) const
         {
            return Vector3(X * vec.X, Y * vec.Y, Z * vec.Z);
         }

         /* preforms a component-wise product with the given vector 
         and sets this vector to the result */
         void component_product_update(const Vector3& vec) 
         {
            X *= vec.X;
            Y += vec.Y;
            Z += vec.Z;
         }

         /* calculates and returns the scalar product of this vector
         with the given vector */
         real scalar_product(const Vector3& vec ) const
         {
            return X*vec.X + Y*vec.Y + Z*vec.Z;
         }

         /* calculates and returns the scalar product of this vector
         with the given vector */
         real operator*(const Vector3& vec) const
         {
            return X*vec.X + Y*vec.Y + Z*vec.Z;
         }

         /* calculates and returns the vector product of this vector
         with the given vector */
         Vector3 vector_product(const Vector3& vec ) const
         {
            return Vector3(Y*vec.Z - Z*vec.Y, 
                           Z*vec.X - X*vec.Z, 
                           X*vec.Y - Y*vec.X);
         }

         /* updates this vectorto be the product of its current value
         and the given vector */
         Vector3 operator%=(const Vector3& vec )
         {
            *this = vector_product(vec);
         }

         /* calculates and returns the vector product of this vector
         with the given vector */
         Vector3 operator%(const Vector3& vec ) const
         {
            return Vector3(Y*vec.Z - Z*vec.Y, 
                           Z*vec.X - X*vec.Z, 
                           X*vec.Y - Y*vec.X);
         }

         void make_orthonormal_basis(Vector3* a, Vector3* b, Vector3* c)
         {
            a->normalize();
            (*c) = (*a) % (*b); 
            if (c->squared_magnitude() == 0.0) { return;} //or throw error
            c->normalize();
            (*b) = (*a) % (*c)
         }
         
         ///////////////////////////////////////////////////////////
         // vector calculus

         //to update the position of a vector

         //position += velocity * t;
         //position.add_scaled_vector(velocity,t); 

   };  

}