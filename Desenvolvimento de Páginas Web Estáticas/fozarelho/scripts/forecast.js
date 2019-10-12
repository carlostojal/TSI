
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/forecast.js 
// github.com/carlostojal/TSI
// 

// Código responsável por obter previsão meteorológica da API do serviço OpenWeatherMap

// Link da API
var forecastlink = "https://api.openweathermap.org/data/2.5/forecast?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&lang=pt&units=metric";
var forecastlink_en = "https://api.openweathermap.org/data/2.5/forecast?apikey=c9f1d2a6eaec5f917473c187547ba288&id=2267937&units=metric";

// Função que obtém a previsão em forma de objeto a partir do JSON retornado pela REST API
function getForecast() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", forecastlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText);
}

// Função que obtém a previsão em forma de objeto a partir do JSON retornado pela REST API, em inglês
function getForecastEn() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", forecastlink_en, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText);
}

// Função que obtém a data da previsão em forma de texto
function getForecastStringDate(forecast) {
    return forecast.dt_txt;
}

// Função que obtém a data
function getForecastDate(forecast) {
    return Date.parse(forecast.dt_txt);
}

// Função que obtém a descrição do estado meteorológico da previsão (céu limpo, nublado, etc.)
function getForecastStatus(forecast) {
    return forecast.weather[0].description;
}

// Função que obtém a temperatura da previsão
function getForecastTemp(forecast) {
    return forecast.main.temp.toFixed(1);
}

// Função que obtém a temperatura máxima da previsão
function getForecastMaxTemp(forecast) {
    return forecast.main.temp_max.toFixed(1);
}

// Função que obtém a temperatura mínima da previsão
function getForecastMinTemp(forecast) {
    return forecast.main.temp_min.toFixed(1);
}