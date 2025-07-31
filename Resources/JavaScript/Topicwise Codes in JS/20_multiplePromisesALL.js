const anikaitPromise = new Promise((resolve, reject) => {

    setTimeout(() => {
        if(Math.random() > 0.5){
            resolve("Anikait: Hey I am in for Goa")
        }
        else{
            reject("Anikait: I am not coming to Goa, I have to study")
        }
    }, 3000)

})

const rachitPromise = new Promise((resolve, reject) => {

    setTimeout(() => {
        if(Math.random() > 0.5){
            resolve("Rachit: Hey I am in for Goa")
        }
        else{
            reject("Rachit: I am not coming to Goa")
        }
    }, 5000)

})

const adityaPromise = new Promise((resolve, reject) => {

    setTimeout(() => {
        if(Math.random() > 0.5){
            resolve("Aditya: Hey I am in for Goa")
        }
        else{
            reject("Aditya: I am not coming to Goa, I am busy with work")
        }
    }, 2000)

})

Promise.all([adityaPromise, anikaitPromise, rachitPromise]).then((msg) => {
    console.log(msg)
    console.log("Finally, we are going to goa")
}).catch((msg) => {
    console.log(msg)
    console.log("Stop planning Goa trip")
})