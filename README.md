# Emscripten-SDL-Template
 Simple Template Code for Emscripten and SDL Projects
# I WILL MAKE THIS PRETTIER SOON
Build instructions:
1. clone code
2. em++ main.cpp -o index.html --shell-file index_template.html -s USE_SDL=2
3. python -m http.server
4. go to http://localhost:8000/
