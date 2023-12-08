export function sendItToEsp(url, hour, minutes) {
    console.log(hour);
    fetch('https://asd.comz/', {
  method: 'POST',
  headers: {
    Accept: 'application/json',
    'Content-Type': 'application/json',
  }, body: JSON.stringify({
    firstParam: 'yourValue',
    secondParam: 'yourOtherValue',
  }),
});
   
}