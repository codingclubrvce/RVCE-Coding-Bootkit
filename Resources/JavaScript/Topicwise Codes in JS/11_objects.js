const user = {
    name: "Samkit",
    age : 18,
    city : "Bengaluru"
}
/**
 * const obj_name = {
 *  key : value,
 *  ...
 * }
 */

console.log(user.name)
console.log(user['age'])

user.country = "India"
user['continent'] = "Asia"

console.log(user)

delete user.country
delete user['continent']

console.log(user)

let person = {
    name : "samkit",
    age : 18,
    address : {
        city : "Bengaluru",
        state : "Karnataka",
        country : "India",
        continent : "Asia"
    }
}

for(let key in person){
    console.log(key, " => ", person[key])
}

console.log(Object.keys(person))//[ 'name', 'age', 'address' ]
console.log(Object.values(person))

console.log(Object.entries(person))
/**
 * [
    [ 'name', 'samkit' ],
    [ 'age', 18 ],
    [
      'address',
      {
        city: 'Bengaluru',
        state: 'Karnataka',
        country: 'India',
        continent: 'Asia'
      }
    ]
  ]
 */

//Cloning an object using assign
const new_person = Object.assign({}, person)
console.log(new_person)
//adding new key and values
const new_person1 = Object.assign({}, person, {role: "Student"})
console.log(new_person1)