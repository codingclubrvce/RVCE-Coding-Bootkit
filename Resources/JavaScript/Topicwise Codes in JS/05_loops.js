for(var i = 0; i<10; i++){
    console.log("Hello World")
}

var j = 0;
while(j<10){
    console.log("Samkit Samsukha")
    j++;
}

for(var i =1; i <= 50; i++){
    if(i%2 != 0){
        continue //things after this not executed, loops restarts.
    }
    console.log(i)
}