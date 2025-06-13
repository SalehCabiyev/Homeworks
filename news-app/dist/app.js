"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
const API_KEY = "82f309ed51114ab8870522e6c45d9e50";
const PAGE_SIZE = 5;
const CATEGORIES = ["general", "business", "entertainment", "health", "science", "sports", "technology"];
let category = "general";
let page = 1;
let totalResults = 0;
const categorySelect = document.getElementById("category");
const loader = document.getElementById("loader");
const errorBox = document.getElementById("error");
const newsList = document.getElementById("news-list");
const prevBtn = document.getElementById("prev");
const nextBtn = document.getElementById("next");
const pageInfo = document.getElementById("page-info");
CATEGORIES.forEach(cat => {
    const option = document.createElement("option");
    option.value = cat;
    option.textContent = cat;
    categorySelect.appendChild(option);
});
categorySelect.value = category;
categorySelect.addEventListener("change", () => {
    category = categorySelect.value;
    page = 1;
    fetchNews();
});
prevBtn.addEventListener("click", () => {
    if (page > 1) {
        page--;
        fetchNews();
    }
});
nextBtn.addEventListener("click", () => {
    if (page < Math.ceil(totalResults / PAGE_SIZE)) {
        page++;
        fetchNews();
    }
});
function fetchNews() {
    return __awaiter(this, void 0, void 0, function* () {
        loader.classList.remove("hidden");
        errorBox.classList.add("hidden");
        newsList.innerHTML = "";
        try {
            const res = yield fetch(`https://newsapi.org/v2/top-headlines?category=${category}&pageSize=${PAGE_SIZE}&page=${page}&country=us&apiKey=${API_KEY}`);
            const data = yield res.json();
            if (data.status !== "ok")
                throw new Error(data.message || "Ошибка загрузки новостей");
            totalResults = data.totalResults;
            data.articles.forEach((article) => {
                const div = document.createElement("div");
                div.className = "news-item";
                div.innerHTML = `
        <h2>${article.title}</h2>
        <p><em>${new Date(article.publishedAt).toLocaleString()}</em></p>
        <p>${article.description || ""}</p>
        <a href="${article.url}" target="_blank">Читать полностью</a>
      `;
                newsList.appendChild(div);
            });
            pageInfo.textContent = `Страница ${page} из ${Math.ceil(totalResults / PAGE_SIZE)}`;
        }
        catch (err) {
            errorBox.textContent = err.message;
            errorBox.classList.remove("hidden");
        }
        finally {
            loader.classList.add("hidden");
        }
    });
}
fetchNews();
console.log("Привет, TypeScript!");
