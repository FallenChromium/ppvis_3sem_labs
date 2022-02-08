namespace geometry {
    class SpacialShape {
        protected:
            float _x,_y,_z;
        public:

        /*! A SpacialShape constructor, takes coordinates in 3D space
        \param x coordinate x 
        \param y coordinate y
        \param z coordinate z 
        */
        SpacialShape(float x, float y, float z);
        SpacialShape();
        virtual float surface_area() = 0;
        virtual float volume() = 0;
        float getX();
        float getY();
        float getZ();

    };

    class Sphere : virtual private SpacialShape {
        protected:
        float _radius;
        public:
        /*! Takes coordinates in space and radius
        \param radius radius of the sphere */
        Sphere(float x, float y, float z, float radius): SpacialShape(x, y, z) {this->_radius = radius;};
        float volume() override;
        float surface_area() override;
    };

    class Prism : virtual public SpacialShape {
        protected:
        int _sideEdges;
        int _baseEdges;
        public:
        /*! Takes coordinates in space and amount of faces, edges for the base, edges for the face and base area
        \param baseEdges amount of edges in the base shape
        \param sideEdges amount of edges on each face
        */
        Prism(float x, float y, float z, int baseEdges, int sideEdges) : SpacialShape(x,y,z) {this->_sideEdges = sideEdges; this->_baseEdges=baseEdges;};
    };

    class Cuboid : public geometry::Prism {
  protected:
    //side of a quadrangle
    float _side_face;
    //side of a base square
    float _side_base_a;
    float _side_base_b;

  public:
  /*! Constructor for a cuboid. Takes coordinates, lengths of both sides of the base and height
  \param side_base_a length of either side of a base 
  \param side_base_b length of another side of a base
  \param side_face height of the Cuboid */ 
    Cuboid(float x, float y, float z, float side_face, float side_base_a, float side_base_b):
      geometry::Prism(x, y, z, 4, 4)  {this->_side_face = side_face; this->_side_base_a=side_base_a; this->_side_base_b=side_base_b;};
      float volume() override;
      float surface_area() override;
};

class PlatonicSolid : virtual protected SpacialShape {
  protected:
    int _vertices;
    int _sideVertices;
  public:
    PlatonicSolid(float x, float y, float z, int vertices, int sideVertices) : SpacialShape(x,y,z) {this->_vertices = vertices; this->_sideVertices=sideVertices;};
};

class Cube : public Cuboid, public geometry::PlatonicSolid {
  protected:
    int _side;
  public:
    Cube(float x, float y, float z, float side) : 
    PlatonicSolid(x,y,z,8,4), Cuboid(x,y,z,side,side,side)
    //, SpacialShape(x, y, z)
     {this->_side = side;}
    using Cuboid::surface_area;
    using Cuboid::volume;
};

}