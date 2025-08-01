/**
 * String
 * - sequence of characters
 */
let name = "Samkit"
console.log(typeof name)
console.log(name[0])
console.log(name[1])
console.log(name[2])
//string is immutable - hence used to store sensitive information
name[2] = "Z" //no effect
console.log(name) //Samkit

console.log(name.length)
let firstName = "Samkit"
let lastName = "Samsukha"
let fullName = firstName.concat(lastName)
console.log(fullName)
console.log(firstName + " " + lastName)

console.log(fullName.toUpperCase())
console.log(fullName.toLowerCase())

console.log(name.charAt(3)) //k

//slicing
console.log(fullName)
console.log(fullName.slice(2)) //2 onwards all //mkitSamsukha
console.log(fullName.slice(2, 5)) //2 to 4 (5-1) //mki
console.log(fullName.slice(-5)) //last five - sukha
console.log(fullName.slice(-5, -1)) //sukh

console.log(name.indexOf('m')) //2

let word = "    Spaces        ";
console.log(word)
console.log(word.trim())

name = "Samkit Vineet Samsukha"
console.log(name.split(""))