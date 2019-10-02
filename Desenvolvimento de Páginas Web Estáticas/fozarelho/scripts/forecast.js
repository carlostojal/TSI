
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/forecast.js 
// 

// Código responsável por obter informação meteorológica da API do serviço OpenWeatherMap por 5 dias, de 3 em 3 horas

var forecastlink = "https://api.openweathermap.org/data/2.5/forecast?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&lang=pt&units=metric";

function getForecast() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", forecastlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText);
}

function getForecastStringDate(forecast) {
    return forecast.dt_txt;
}

function getForecastDate(forecast) {
    return Date.parse(forecast.dt_txt);
}

function getForecastStatus(forecast) {
    return forecast.weather[0].description;
}

function getForecastMaxTemp(forecast) {
    return forecast.main.temp_max;
}

function getForecastMinTemp(forecast) {
    return forecast.main.temp_min;
}