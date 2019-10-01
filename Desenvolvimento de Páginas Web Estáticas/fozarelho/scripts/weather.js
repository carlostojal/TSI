
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/weather.js 
// 

// Código responsável por obter informação meteorológica da API do serviço AccuWeather

var fozlink = "http://dataservice.accuweather.com/locations/v1/cities/search?apikey=Gofa7TWTOGZFhZmti07ybKlxbS9FMsIw&q=Foz+do+Arelho";
var forecastlink = "http://dataservice.accuweather.com/currentconditions/v1/273911?apikey=Gofa7TWTOGZFhZmti07ybKlxbS9FMsIw&language=pt-pt&metric=true";

function getStatus(forecast) {
    return forecast[0].WeatherText;
}

function getTemperature(forecast) {
    return forecast[0].Temperature.Metric.Value;
}

function getForecast() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", forecastlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText); // a função retorna a resposta da API convertida para um objeto JavaScript
}