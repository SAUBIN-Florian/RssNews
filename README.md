# RSS News

RSS News is a lightweight, Qt-based desktop application for reading and managing RSS feeds.  
It provides a clean and simple interface to fetch, update, and display articles from your favorite sources.

## Features
- 📡 **Load and parse RSS feeds**
- 🔄 **Refresh feeds** to get the latest articles
- 🗂 **Organize multiple feeds**
- 📖 **View article summaries** directly in the app
- 💾 **Persistent storage** for your feed list between sessions

## Screenshots
_(Coming soon)_

## Built With
- **C++17**
- **Qt 6 (QtWidgets)**
- **CMake** for build configuration

## Installation
Clone the repository:
```bash
git clone https://github.com/SAUBIN-Florian/RssNews
cd RssNews

cmake -B build -DCMAKE_PREFIX_PATH="""$YOUR_QT6_CMAKE_PATH"""
cmake --build build

./build/RssNews
```

## License
This project is licensed under the MIT License — see the LICENSE file for details.
