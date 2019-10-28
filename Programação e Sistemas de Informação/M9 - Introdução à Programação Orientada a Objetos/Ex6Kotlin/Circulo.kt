
//
// Copyright (c) Carlos Tojal (24-10-2019)
// Ex6Kotlin
// Circulo.kt
//

import kotlin.math;

class Circulo(x: Double, y: Double, raio: Double, raio_aumentado: Double) {
    
    constructor(): this(0.0, 0.0, 0.0, 0.0);
    constructor(x: Double, y: Double, raio: Double): this(x, y, raio, 0.0);

}