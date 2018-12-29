```puml
class Point3D {
  x: double
  y: double
  z: double
}

class Pixel {
  x: double
  y: double
  dist: double
}

class CoordinateSystem {
  affine: Matrix44
  + transformIntoSystem(p: Point3D, o: CoordinateSystem): Point3D
  + rotate(m: Matrix33)
  + rotate(q: Quaternion)
  + rotateX(x: Angle)
  + rotateY(y: Angle)
  + rotateZ(z: Angle)
}

class Object {
  faces: Face[]
}

class Cube {

}

class Tetrahedron {

}

class Face {
  points: Point3D[]
}

class Shape {
  pxs: Pixel[]
  + clip(other: Shape): Shape[]
}

class Camera {
  + transformAndPerspective(p: Point3D): Pixel
  + perspective(p: Point3D): Pixel
  + outOfView(p: Pixel): Boolean
  + outOfView(p: Point3D): Boolean
}

class World {
  objects: Object[]
  cams: Camera[]
  + draw(w: Window, c: Context)
}

CoordinateSystem <|-- Camera
CoordinateSystem <|-- Object
Object <|-- Cube
Object <|-- Tetrahedron
Object *- Face
Face *-- Point3D
World *-- Object
World *-- Camera
Shape *-- Pixel
```
