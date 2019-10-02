
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/weather.js 
// 

// Código responsável por obter informação meteorológica da API do serviço OpenWeatherMap

var forecastlink = "https://api.openweathermap.org/data/2.5/weather?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&lang=pt&units=metric";

function getStatus(forecast) {
    return forecast.weather[0].description;
}

function getTemperature(forecast) {
    return forecast.main.temp;
}

function getWind(forecast) {
    return forecast.wind.speed;
}

function getForecast() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", forecastlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText); // a função retorna a resposta da API convertida para um objeto JavaScript
}