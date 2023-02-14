#include "../headers/Rectangle.h"
#include "../headers/Circle.h"
#include "../headers/Line.h"
#include "../headers/IO.h"

#define SVGEXTENSION ".svg"

ShapeCollection IO::collection;
String IO::currentFile;
bool IO::saved, IO::closed = true, IO::changes;
Vector<String> IO::colorNames;

void IO::menu(){

    IO::loadColorNames();
    String command;

    while(true){

        cout << "> ";
        cin >> command;

        if(command == "exit"){
            
            if(closed) break;
            cout << "You haven't closed " << IO::currentFile << '\n';

        }

        else if(command == "help") help();

        else if(command == "open") open();
        else if(command == "save") save();
        else if(command == "saveas") saveas();
        else if(command == "close") close();

        else if(command == "print") print();
        else if(command == "create") create();
        else if(command == "erase") erase();
        else if(command == "translate") translate();
        else if(command == "within") within();
        else if(command == "pointin") pointIn();
        else if(command == "areas") areas();
        else if(command == "pers") pers();

        else cout << "Command " << command << " is not supported!\n";

    }

}

void IO::open(){

    cin >> IO::currentFile;
    IO::currentFile = "images/" + IO::currentFile;

    String fileNameExtension = IO::currentFile.substring(IO::currentFile.length() - 4, strlen(SVGEXTENSION));

    if(fileNameExtension != SVGEXTENSION){

        cout << "File is not an svg file\n";
        return;

    }

    String type;
    ifstream ifs(IO::currentFile.c_str());

    const size_t bufferSize = 1024;
    char temp[bufferSize];
    ifs.getline(temp, bufferSize);
    ifs.getline(temp, bufferSize);
    ifs.getline(temp, bufferSize);

    while(true){

        while(ifs.get() != '<');
        ifs >> type;

        if(type == "rect"){
            
            Rectangle *rect = new Rectangle();
            rect -> deserialize(ifs);
            IO::collection.addShape(rect);
            delete rect;

        }
        else if(type == "circle"){
            
            Circle *circle = new Circle();
            circle -> deserialize(ifs);
            IO::collection.addShape(circle);
            delete circle;

        }
        else if(type == "line"){

            Line *line = new Line();
            line -> deserialize(ifs);
            IO::collection.addShape(line);
            delete line;

        }
        else if(type == "/svg>") break;
        
    }

    IO::saved = false;
    IO::closed = false;
    IO::changes = false;
    ifs.close();
    cout << "Successfully opened " << IO::currentFile << '\n';

}

void IO::save(){

    ofstream ofs(IO::currentFile.c_str(), ios::trunc);

    ofs << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
        << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
        << "<svg>\n";
    for(size_t i = 0; i < IO::collection.size(); i++)
        IO::collection[i] -> serialize(ofs);
    ofs << "</svg>";

    IO::saved = true;
    IO::changes = false;
    ofs.close();
    cout << "Successfully saved the changes to " << IO::currentFile << '\n';

}

void IO::saveas(){

    cin >> IO::currentFile;
    IO::currentFile = "images/" + IO::currentFile;
    
    String fileNameExtension = IO::currentFile.substring(IO::currentFile.length() - 4, strlen(SVGEXTENSION));

    if(fileNameExtension != SVGEXTENSION){

        cout << "File is not an svg file\n";
        return;

    }

    ofstream ofs(IO::currentFile.c_str(), ios::trunc);

    ofs << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
        << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
        << "<svg>\n";
    for(size_t i = 0; i < IO::collection.size(); i++)
        IO::collection[i] -> serialize(ofs);
    ofs << "</svg>";

    IO::saved = true;
    IO::changes = false;
    ofs.close();
    cout << "Successfully saved the changes to " << IO::currentFile << '\n';

}

void IO::close(){

    if(IO::changes && !IO::saved){

        String input;

        cout << "File has not been saved!\nsave/saveas/cancel?\n>";
        cin >> input;

        if(input == "save") save();
        else if(input == "saveas");

    }

    IO::currentFile = "";
    IO::collection.clear();
    IO::closed = true;

}

void IO::help(){

    cout << "Supported shapes are:\n"
        << "Circle - centerx centery radius color\n"
        << "Rectangle - x y width height color(x and y are in the top left corner)\n"
        << "Line - x1 y1 x2 y2 color\n\n"

        << "Supported commands are:\n"
        << "File commands:\n"
        << "open <file name>.svg - Opens svg file in the editor.\n"
        << "save - Saves the currently opened file.\n"
        << "saveas <file name>.svg - Saves the currently opened file as new file.\n"
        << "close - Closes the currently opened file if it has been saved.\n\n"

        << "Editor commands are:\n"
        << "print - Prints out the file information about all the figures.\n"
        << "create <shape> [<params of shape>] - Creates new shape with the specified parameters.\n"
        << "erase <index> - Erases figure on the specified index(1-n).\n"
        << "translate [<figure index>] <x translation> <y translation> - If figure index is not specified it translates all the shapes, otherwise only the specified.\n"
        << "within <shape> [<params of shape>] - Prints every shape that is fully inside the specified shape.\n"
        << "pointin <x> <y> - Prints every shape that the specified point lies in.\n"
        << "areas - Prints every shapes area.\n"
        << "pers - Prints every shapes perimeter.\n\n"

        << "Util commands are:\n"
        << "help - Prints out this menu.\n"
        << "exit - Exits the program and saves opened files if not saved.\n";

}

void IO::print(){

    for(size_t i = 0; i < IO::collection.size(); i++)
        cout << i + 1 << ". " << IO::collection[i] -> toString() << '\n';

}
void IO::create(){

    String shape;

    cin >> shape;

    if(shape == "rectangle"){

        size_t x, y, width, height;
        String color;

        cin >> x >> y >> width >> height >> color;

        if(!IO::colorNames.contains(color)){

            cout << "Invalid color name\n";
            return;

        }

        IO::collection.addShape(new Rectangle(x, y, width, height, color));

    }
    else if(shape == "circle"){
        
        size_t x, y, radius;
        String color;

        cin >> x >> y >> radius >> color;

        if(!IO::colorNames.contains(color)){

            cout << "Invalid color name\n";
            return;

        }

        IO::collection.addShape(new Circle(x, y, radius, color));

    }
    else if(shape == "line"){
       
        size_t x1, y1, x2, y2;
        String color;

        cin >> x1 >> y1 >> x2 >> y2 >> color;

        if(!IO::colorNames.contains(color)){

            cout << "Invalid color name\n";
            return;

        }

        IO::collection.addShape(new Line(x1, y1, x2, y2, color));

    }

    cout << "Successfully created " << shape << " (" << IO::collection.size() << ")\n";
    IO::changes = true;
    
}

void IO::erase(){

    size_t index;

    cin >> index;

    --index;

    if(IO::collection.size() <= index){

        cout << "There is no figure number " << index + 1 << "!\n";
        return;

    }

    collection.removeShape(index);
    cout << "Erased a circle (" << index + 1 << ")\n";
    IO::changes = true;

}

void IO::translate(){
    
    String input;

    cin >> input;

    cout << input << '\n';

    if(input.contains('=')){

        int index1 = input.find('=') + 1;
        input = String(input.substring(index1, input.length() - index1));

        String xTranslation;

        cin >> xTranslation;

        int index2 = xTranslation.find('=') + 1;
        xTranslation = String(xTranslation.substring(index2, xTranslation.length() - index2));

        for(size_t i = 0; i < IO::collection.size(); i++)
            IO::collection[i] -> translate(atof(input.c_str()), atof(xTranslation.c_str()));

        cout << "Translated all figures\n";

    }
    else{

        String xTranslation, yTranslation;

        cin >> yTranslation >> xTranslation;
        
        int indexX = xTranslation.find('=') + 1;
        int indexY = yTranslation.find('=') + 1;

        IO::collection[atoi(input.c_str())] -> translate(atof(xTranslation.c_str()), atof(yTranslation.c_str()));

        cout << "Translated figure at index: " << input << '\n';

    }

    IO::changes = true;

}

void IO::within(){

    String type;

    cin >> type;
    
    if(type == "rectangle"){

        double x, y, width, height;

        cin >> x >> y >> width >> height;
        
        for(size_t i = 0; i < IO::collection.size(); i++)
            if(IO::collection[i] -> isInsideRectangle(x, y, width, height))
                cout << i + 1 << ". " << IO::collection[i] -> toString() << '\n';

    }
    else if(type == "circle"){
        
        double x, y, radius;

        cin >> x >> y >> radius; 
        
        for(size_t i = 0; i < IO::collection.size(); i++)
            if(IO::collection[i] -> isInsideCircle(x, y, radius))
                cout << i + 1 << ". " << IO::collection[i] -> toString() << '\n';

    }

}

void IO::pointIn(){

    double x, y;

    cin >> x >> y;

    for(size_t i = 0; i < IO::collection.size(); i++)
        if(collection[i] -> isPointIn(x,y))
            cout << i + 1 << ". " << IO::collection[i] -> toString() << '\n';

}

void IO::areas(){

    for(size_t i = 0; i < IO::collection.size(); i++)
        cout << i + 1 << ". " << "Shape area: " << IO::collection[i] -> getArea() <<  '\n';

}

void IO::pers(){
    
    for(size_t i = 0; i < IO::collection.size(); i++)
        cout << i + 1 << ". " << "Shape per: " << IO::collection[i] -> getPer() <<  '\n';

}

void IO::loadColorNames(){

    ifstream ifs("utils/colors.txt");
    String color;
    while(ifs >> color) IO::colorNames.pushBack(color);
    ifs.close();

}