arr = [1, 2, 3]
console.log(typeof arr)
console.log(arr)

arr1 = new Array()
console.log(typeof arr1)
console.log(arr1)

a = [1, 2, 3, 4, 9, 8, 7, 19, 21, 29, 20]
console.log(a[1])
console.log(a[7])
console.log(a[10])

//Arrays are mutable
a[1] = 1000
console.log(a)

a.push(1111) //insert at the end of array
console.log(a)

a.push(99, 100, 101)
console.log(a)

a.unshift(-2, -1, 0) //insert at the beginning of the array
console.log(a)

console.log(a.pop()) //removes 101
console.log(a.shift()) //removes -1
console.log(a)

let a1 = [1, 2, 3]
let a2 = [4, 5, 6]
let result = a1.concat(a2)
console.log(result)
console.log(result.length)

//convert array to string
chArray = ["s", "a", "m", "k", "i", "t"]
console.log(chArray.join()) //s,a,m,k,i,t
console.log(chArray.join("")) //samkit
console.log(chArray.join("-")) //s-a-m-k-i-t

let a3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
console.log(a3.slice(2)) //3 onwards all
console.log(a3.slice(2, 7)) //3, 4, 5, 6, 7, 
console.log(a3.slice(5, -1)) //6, 7, 8, 9, 10, 11, 12, 13, 14
console.log(a3.slice(-9, -2)) //7, 8, 9, 10, 11, 12, 13
console.log(a3.slice(2, -1)) //3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14

let a4 = [1, 2, 3, 4, 5]
let removed = a4.splice(2, 2) //remove 2 elements from index 2
console.log(removed) //3, 4
console.log(a4) //1, 2, 5

let a5 = [1, 2, 3, 4, 5]
let removed1 = a5.splice(2, 2, 11, 12, 13) //remove 2 elements from index 2 and add 11, 12, 13
console.log(removed1) //3, 4
console.log(a5) //1, 2, 11, 12, 13, 5

let a6 = [4, 1, 7, 9, 2]
a6.reverse()
console.log(a6)
console.log(a6.indexOf(9))

let a7 = [5, 4, 1, 3, 2]
a7.sort()
console.log(a7) //1, 2, 3, 4, 5

let a8 = [15, 40, 1, 13, 2]
a8.sort()
console.log(a8) // 1, 13, 15, 2, 40
/*******************************************/
a8.sort((a, b) => a-b) //ascending order
console.log(a8)
a8.sort((b, a) => a-b) //descending order
console.log(a8)

