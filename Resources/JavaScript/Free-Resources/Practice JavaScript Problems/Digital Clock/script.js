let hours = document.querySelector(".hours")
let minutes = document.querySelector(".minutes")
let seconds = document.querySelector(".seconds")
let date = document.querySelector(".date");
let _today = document.querySelector(".day")

setInterval(() => {
  let time = new Date();
  let hour = time.getHours();
  let minute = time.getMinutes();
  let second = time.getSeconds();
  if (hour < 10) {
    hours.innerText = '0' + hour + ' : ';
  }
  else {
    hours.innerText = hour + ' : ';
  }
  if (minute < 10) {
    minutes.innerText = '0' + minute + ' : ';
  }
  else {
    minutes.innerText = minute + ' : ';
  }
  if (second < 10) {
    seconds.innerText = '0' + second;
  }
  else {
    seconds.innerText = second;
  }
  console.log(minute);
  console.log(second);

  let day = numberToWeekday(time.getDay());
  _today.innerText = day;
  let _date = time.getDate();
  let month = numberToMonth(time.getMonth());
  let year = time.getFullYear();
  let today = month + ' ' + _date + ' , ' + year
  date.innerText = today;
}, 1000)

function numberToWeekday(num) {
  const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
  return days[num % 7]; // %7 to handle numbers >6
}
function numberToMonth(num) {
  const months = [
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  ];
  return months[num % 12]; // %12 to handle numbers >11
}