import java.util.*

import kotlin.math.sqrt

 

fun main() {

 

    val read = Scanner(System.`in`)

 

    println("To form quadratic equation a * x * x + b * x + c = 0")

 

    println("Enter a:")

    val a = read.nextDouble()

 

    println("Enter b:")

    val b = read.nextDouble()

 

    println("Enter c:")

    val c = read.nextDouble()

 

    val d: Double = (b * b) - (4 * a * c)       // This is determinant that decides whether roots are real or imaginary

 

    when {

        (d > 0) -> {

            val firstRoot = (-b + sqrt(d)) / ( 2 * a)

            val secondRoot = (-b - sqrt(d)) / ( 2 * a)

 

            val output = "Roots of equation a * x * x + b * x + c = 0 => x = %.2f and x = %.2f"

                    .format(firstRoot, secondRoot)

            println(output)

        }

        (d == 0.0) -> {

            val firstRoot = -b / ( 2 * a)

 

            val output = "Roots of equation a * x * x + b * x + c = 0 => x = %.2f and x = %.2f"

                    .format(firstRoot, firstRoot)

            println(output)

        }

        else -> {

            val realPart = -b / ( 2 * a)

            val imaginaryPart = sqrt(-d) / (2 * a)

 

            val output =

                "Roots of equation a * x * x + b * x + c = 0 => x = (%.2f + %.2fi) and x = (%.2f - %.2fi)"
.format(realPart, imaginaryPart, realPart, imaginaryPart)

            println(output)

        }

    }

 

}


