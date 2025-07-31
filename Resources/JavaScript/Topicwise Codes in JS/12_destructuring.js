//Fetch values from Array and Objects and assign it to variables

const nums = [1, 2, 3]
const [a, b, c, d] = nums
console.log(a)
console.log(b)
console.log(c)
console.log(d) //undefined

const [p, q, r] = [1, 2, [4, 5, 6]]
console.log(p)
console.log(q)
console.log(r) //[ 4, 5, 6 ]

const per = {
    age : 18,
    name : "Samkit",
    
    address : {
        city : "bengaluru",
        state : "karnataka"
    }
}

const {name, age, address:{city, state}} = per
console.log(name)
console.log(age)
console.log(city)
console.log(state)