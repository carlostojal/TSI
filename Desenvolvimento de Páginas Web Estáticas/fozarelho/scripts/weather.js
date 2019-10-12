
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/weather.js 
// github.com/carlostojal/TSI
// 

// Código responsável por obter meteorologia atual da API do serviço OpenWeatherMap

// Link da API
var weatherlink = "https://api.openweathermap.org/data/2.5/weather?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&lang=pt&units=metric";
var weatherlink_en = "https://api.openweathermap.org/data/2.5/weather?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&units=metric";

// Função que obtém o objeto a partir do JSON retornado pela REST API
function getWeather() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", weatherlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText);
}

// Função que obtém o objeto a partir do JSON retornado pela REST API, em inglês
function getWeatherEn() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", weatherlink_en, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText);
}

// Função que obtém o texto que descreve como está o clima (céu limpo, nublado, etc.)
function getStatus(weather) {
    return weather.weather[0].description;
}

// Função que obtém a temperatura
function getTemperature(weather) {
    return weather.main.temp.toFixed(1);
}

// Função que obtém a velocidade do vento
function getWind(weather) {
    return (weather.wind.speed * 3.6).toFixed(1); //convertido de m/s para km/h
}