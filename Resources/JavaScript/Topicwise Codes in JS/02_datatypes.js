// PRIMITIVE

//String
var name = "Samkit"
var title = 'Samsukha'
console.log(title)
console.log(typeof title)

//Number
var age = 19
console.log(age)
console.log(typeof(age))

//BigInt
var bignum = 123n;
console.log(typeof bignum)

//NaN
console.log(typeof NaN) //Number

//null
console.log(typeof null) //Object

var a
console.log(typeof a) //undefined

//boolean
console.log(typeof true)

//symbol
var s1 = Symbol()

/**********************************************************************************************************/

// OBJECTS
var person = {
    user : "Samkit",
    dob : 141005,
    sport : "cricket"
}
console.log(person)
console.log(typeof person)

const score = "33"
console.log(typeof score)
let valueInNumber = Number(score)
console.log(valueInNumber) //33
console.log(typeof valueInNumber) //string

/**
 * if score is 
 * true/false -> 0, 1
 * "33abc" -> NaN
 * "33" -> 33
 * null -> 0
 */

let isLoggedIn = 1
let booleanIsLoggedIn = Boolean(isLoggedIn)
console.log(isLoggedIn) //1
console.log(booleanIsLoggedIn) //true

/**
 * 1 -> true
 * 0 -> false
 * "" -> false
 * "samkit" -> true
 */

let num = 33;
let snum = String(num)
console.log(typeof snum) //string