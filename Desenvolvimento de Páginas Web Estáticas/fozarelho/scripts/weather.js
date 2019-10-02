
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/weather.js 
// 

// Código responsável por obter informação meteorológica da API do serviço OpenWeatherMap

var weatherlink = "https://api.openweathermap.org/data/2.5/weather?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&lang=pt&units=metric";

function getWeather() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", weatherlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText);
}

function getStatus(weather) {
    return weather.weather[0].description;
}

function getTemperature(weather) {
    return weather.main.temp;
}

function getWind(weather) {
    return weather.wind.speed;
}