#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "shape.hpp"

#include <vector>
namespace fbg {
   /** A context that holds an array of Shapes and its subclasses.
    * @param attach(): Attaching of shapes to context.
    * @param detach(): Detaching of shapes to context. */
   class Context : public Shape {
   public:
      /** Constructor for Context class.
       * @param o: Origin point. */
      Context(const V2d<float> & o) : Shape { { o } } { };

      /** Constructor for Context class.
       * @param x: x-value for origin point
       * @param y: y-value for origin point */
      Context(float x, float y) : Context { { x, y, }} { };

      /** Default constructor for Context class. 
       * Sets origin to (0, 0) */
      Context() : Context { { 0.0f, 0.0f }} {  };

      ~Context() {
         for (int i = 0; i < numShapes(); i++)
            detach(i);
      }

      /** @return Number of shapes in the object */
      int numShapes() const { return m_shapes.size(); };

      /** @return Vector of pointers to the current shapes */
      const std::vector<Shape *> & getShapes() const { return m_shapes; };

      /** Attach a shape to this context.
       * @param s: The shape to be added */
      void attach(Shape & s) { 
         m_shapes.push_back(&s);
         s.move(origin());
      };

      /** Detach a shape from this context.
       * @param s: The shape to be removed */
      void detach (Shape & s) 
      { 
         for (int i = 0; i < m_shapes.size(); i++) 
            if (*m_shapes[i] == s) {
               detach(i);
            }
      };

      /** Set origin of the context. 
       * @param o: Origin of the context.  */
      void origin(const V2d<float> & o) { 
         V2d<float> oldorg = get_point(0);
         set_point(0, o); 

         for (Shape * s : m_shapes)
            s->move(get_point(0) - oldorg);
      };

      /** Set origin of the context.
       * @param x: x-value for origin
       * @param y: y-value for origin */
      void origin(float x, float y) { origin({x, y}); };

      /** Get origin of the context.
       * @returns Origin point for context. */
      const V2d<float> & origin() const { return get_point(0); };

      void rotate(float a, const V2d<float> & p) 
      {
         for (Shape * s : m_shapes)
            s->rotate(a, p);
      };

      /** Rotate around the origin of the centre 
       * @param a: The angle to rotate by. */
      void rotate(float a) 
      {
         for (Shape * s : m_shapes)
            s->rotate(a, get_point(0));
      }

      /** Rotate the context around the given point (x, y).
       * @param a: The angle to rotate by
       * @param x: The x-value of the reference-point
       * @param y: The y-value of the reference-point */
      void rotate(float a, float x, float y) { Context::rotate(a, {x, y}); };

      void move(const V2d<float> & v) 
      {
         for (Shape * s : m_shapes)
            s->move(v);
      }

      void move(float x, float y) { Context::move({x, y}); };

   private:
      friend class Window; // allow for window to use draw_fill

      /** Empty: 
       * Drawing of shapes in ths context is done within the the draw_fill method. */
      void draw_stroke(Frame & f) {	};

      /** Draw pixels of every object in this context.
       * @param f: The Frame to draw the pixels to. */
      void draw_fill(Frame & f) 
      {
         for (Shape * s : m_shapes) {
            s->draw_fill(f);
            s->draw_stroke(f);
         }
      }

      // private function
      void detach(int i) {
         std::vector<Shape *>::iterator sit = m_shapes.begin() + i;
         Shape * s = *sit;

         s->move(V2d<float> { 0, 0 } - origin());

         m_shapes.erase(m_shapes.begin() + i);
      }

      std::vector<Shape *> m_shapes;
   };
};
#endif