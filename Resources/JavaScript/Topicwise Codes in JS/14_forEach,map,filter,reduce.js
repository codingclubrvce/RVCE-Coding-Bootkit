//forEach

let players = ["sachin", "virat", "dhoni", "rohit"]
players.forEach((player) => {
    console.log(player)
})

//map - creation of new transformed array

let arr = [1, 2, 3, 4, 5, 6]
cubeArr = arr.map(num => num**3)
console.log(cubeArr)

//filter

let arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
let evenArr = arr1.filter((num) => num%2==0)
console.log(evenArr)

//reduce

const sum = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].reduce((current, next) => current + next)
console.log(sum)