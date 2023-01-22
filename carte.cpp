#include "carte.h"

Carte_t::Carte_t(std::string path) {
    surfaceTotal = 0;
    std::ifstream file(path);
    if(file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // gestion des infos de la parcelles
            std::vector<std::string> tokens;
            std::vector<std::string> coordonees;
            std::string delimiter = " ";
            tokens = split(line, delimiter);

            // gestion des coordonnées de la parcelle
            std::getline(file, line);
            line.erase(std::remove(line.begin(), line.end(), '['), line.end());
            line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
            coordonees = split(line, delimiter);
            std::vector<Point2D_t<int>> points;
            for(int i = 0; i < coordonees.size(); i++) {
                points.push_back(parsePoint(coordonees[i]));
            }
            Polygone_t<int> poly(points);
            surfaceTotal += poly.getSurface();

            // remplissage de la liste
            if(tokens[0] == "ZU") {
                zu_t zu(std::stoi(tokens[1]), tokens[2], poly, std::stof(tokens[4]));
                std::cout << zu << "\n";
                this->push_back(&zu);
            }
            else if(tokens[0] == "ZAU") {
                zau_t zau(std::stoi(tokens[1]), tokens[2], poly);
                std::cout << zau << "\n";
                this->push_back(&zau);
            }
            else if(tokens[0] == "ZA") {
                za_t za(std::stoi(tokens[1]), tokens[2], poly, tokens[3]);
                std::cout << za << "\n";
                this->push_back(&za);
            }
            else if(tokens[0] == "ZN") {
                zn_t zn(std::stoi(tokens[1]), tokens[2], poly);
                std::cout << zn << "\n";
                this->push_back(&zn);
            }
            else {
                std::cerr << "Premier token de la ligne different de ZU, ZAU, ZA ou ZN\n";
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }
}

Carte_t::~Carte_t() {
}

std::vector<std::string> Carte_t::split(std::string s, std::string delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    size_t pos;
    while((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    if(s.size() != 0) {
        tokens.push_back(s);
    }
    return tokens;
}

Point2D_t<int> Carte_t::parsePoint(std::string token) {
    int x, y;
    x = std::stoi(token.substr(0, token.find(";")));
    y = std::stoi(token.substr((token.find(";") + 1), token.size()));
    Point2D_t<int> to_return(x, y);
    return to_return;
}

void Carte_t::save() {
    std::ofstream file("save_parc.txt");
    if(file.is_open()) {
        Carte_t::iterator it;
        for(it = this->begin(); it != this->end(); it++) {
            std::cout << (*it)->getType() << " " << (*it)->getNumero() << "\n";
            std::cout << (*it)->getForme() << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file (in save function)\n";
    }
}