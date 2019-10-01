
//
// Copyright (c) Carlos Tojal (carlostojal)
// Foz do Arelho
// scripts/weather.js 
// 

// Código responsável por obter informação meteorológica da API do serviço AccuWeather

var fozlink = "http://dataservice.accuweather.com/locations/v1/cities/search?apikey=Gofa7TWTOGZFhZmti07ybKlxbS9FMsIw&q=Foz+do+Arelho";
var weatherlink = "http://dataservice.accuweather.com/forecasts/v1/hourly/1hour/273911?apikey=Gofa7TWTOGZFhZmti07ybKlxbS9FMsIw&language=pt-pt&metric=true";

function getStatus(forecast) {
    return forecast[0].IconPhrase;
}

function getTemperature(forecast) {
    return forecast[0].Temperature.Value;
}

function getPrecipitationProbability(forecast) {
    return forecast[0].PrecipitationProbability;
}

function getForecastNextHour() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", weatherlink, false);
    xmlHttp.send(null);
    return JSON.parse(xmlHttp.responseText); // a função retorna a resposta da API convertida para um objeto JavaScript
}