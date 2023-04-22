#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string src_map, src_status, src_orders;
    int time_limit = 5;

    if (argc >= 4) {
        src_map = argv[1];
        src_status = argv[2];
        src_orders = argv[3];
        time_limit = std::stoi(argv[4] ? argv[4] : "5");
    }
    else if(src_map!="mapa.txt"){
        std::cerr << "Niepoprawna nazwa pliku przekazana w pierwszym argumencie. Powinno być \"mapa.txt\".\n";
        return 1;
    }
    else if(src_status!="status.txt"){
        std::cerr << "Niepoprawna nazwa pliku przekazana w drugim argumencie. Powinno być \"status.txt\".\n";
        return 1;
    }
    else if(src_orders!="rozkazy.txt"){
        std::cerr << "Niepoprawna nazwa pliku przekazana w trzecim argumencie. Powinno być \"rozkazy.txt\".\n";
        return 1;
    }
    else if(time_limit > 0){
        std::cerr << "Podany czas musi być większy od 0\n";
        return 1;
    }

    std::cout << "arg1: " << src_map << '\n';
    std::cout << "arg2: " << src_status << '\n';
    std::cout << "arg3: " << src_orders << '\n';
    std::cout << "arg4: " << time_limit << '\n';

    return 0;
}
