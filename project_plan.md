```puml
class Point3D {
  x: double
  y: double
  z: double
}

class Point2D {
  x: double
  y: double
}

class CoordinateSystem {
  affine: Matrix44
  + transformIntoSystem(p: Point3D, o: CoordinateSystem): Point3D
  + rotate(m: Matrix33)
  + rotate(q: Quaternion)
  + rotateX(x: Angle)
  + rotateY(y: Angle)
  + rotateZ(z: Angle)
  +<u>identity()
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

class Camera {
  + perspective(p: Point3D): Point2D
}

class World {
  objects: Object[]
  cams: Camera[]
  + drawScene(w: Window, c: Context)
}

class Panel {
  drawArea: Window
}

CoordinateSystem <|-- Camera
CoordinateSystem <|-- Object
Object <|-- Cube
Object <|-- Tetrahedron
Object *-- Face
Face *-- Point3D
World o-- Object
World o-- Camera

```
