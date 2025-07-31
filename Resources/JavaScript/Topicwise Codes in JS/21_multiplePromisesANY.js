const girl1Promise = new Promise((resolve, reject) => {

    setTimeout(() => {
        if(Math.random() > 0.5){
            resolve("GF1: Yes I will come for dinner")
        }
        else{
            reject("GF1: I am busy with my boyfriend")
        }
    }, 2000)

})

const girl2Promise = new Promise((resolve, reject) => {

    setTimeout(() => {
        if(Math.random() > 0.5){
            resolve("GF2: Yes I will come for dinner")
        }
        else{
            reject("GF2: I have pain in stomache")
        }
    }, 1000)

})

const girl3Promise = new Promise((resolve, reject) => {

    setTimeout(() => {
        if(Math.random() > 0.5){
            resolve("GF3: Yes I will come for dinner")
        }
        else{
            reject("GF3: I am studying for exam")
        }
    }, 3000)

})

Promise.any([girl1Promise, girl2Promise, girl3Promise]).then((msg) => {
    console.log(msg)
    console.log("I got a girl")
}).catch((msg) => {
    console.log(msg)
    console.log("I am joining Bajrang Dal")
})