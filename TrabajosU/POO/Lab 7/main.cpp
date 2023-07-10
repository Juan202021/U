#include <iostream>
#include <vector>

using namespace std;

class Likeable{
public:
    virtual void like() = 0;
};

class Commentable{
public:
    virtual void addComment(string) = 0;
};

class Post: public Likeable, public Commentable{
protected:
    string content;
    int likes;
    vector<string> comments;
public:
    Post(string content): content(content), likes(0){
        comments = {};
    }
    void like(){}
    void addComment(string comment){}
    virtual int getTipo() = 0;
    friend ostream& operator<<(ostream& out, Post* p){
        p->print(out);
        out << "Content: " << p->content << endl;
        out << "Likes: " << p->likes << endl;
        out << "Comments: " << endl;
        for (string comment: p->comments){
            out << comment << "\n" << endl;
        }
    }

    string getContent(){
        return content;
    }
    void setContent(string content) {
        this -> content = content;
    }

    int getLikes(){
        return likes;
    }
    void setLikes(int likes) {
        this -> likes = likes;
    }

    vector<string> getComments(){
        return comments;
    }
    void setComments(vector<string> comments) {
        this -> comments = comments;
    }

protected:
    virtual void print(ostream&) = 0;
};

class MediaPost: public Post{
protected:
    string mediaURL;
    MediaPost(string mediaURL, string content): mediaURL(mediaURL), Post(content){}
};

class TextPost : public Post {
public:
    TextPost(string content): Post(content){}
protected:
    void print(ostream& out) { out << "Informacion tipo TextPost" << endl; }
    int getTipo(){ return 1; }
};

class QuotePost : public TextPost {
public:
    string quote;
    QuotePost(string quote, string content):TextPost(content), quote(quote){}
    void print(ostream& out) { out << "Informacion tipo QuotePost" << endl; }
    int getTipo(){ return 2; }
};

class Taggable{
public:
    vector<string> tags;
    void addTag(string tag){ tags.push_back(tag); }
};

class TaggedTextPost: public Taggable, public TextPost {
public:
    TaggedTextPost(string tagged):TextPost(tagged){}
protected:
    void print(ostream& out){ out << "Informacion tipo TaggedTextPost" << endl; }
    int getTipo(){ return 3; }
};

class PhotoPost: public MediaPost{
public:
    PhotoPost(string mediaURL, string content): MediaPost(mediaURL, content){}
protected:
    void print(ostream& out){ out << "Informacion tipo PhotoPost" << endl; }
    int getTipo(){ return 4; }
};

class VideoPost: public MediaPost{
public:
    VideoPost(string mediaURL, string content): MediaPost(mediaURL, content){}
protected:
    void print(ostream& out){ out << "Informacion tipo VideoPost" << endl; }
    int getTipo(){ return 5; }
};

class TaggedPhotoPost: public PhotoPost, virtual public Taggable{
public:
    TaggedPhotoPost(string mediaURL, string content): PhotoPost(mediaURL, content){}
protected:
    void print(ostream& out){ out << "Informacion tipo TaggedPhotoPost" << endl; }
    int getTipo(){ return 6; }
};

class TaggedVideoPost: public VideoPost, virtual public Taggable{
public:
    TaggedVideoPost(string mediaURL, string content): VideoPost(mediaURL, content){}
protected:
    void print(ostream& out){ out << "Informacion tipo TaggedVideoPost" << endl; }
    int getTipo(){ return 7; }
};

void encabezado(){
    cout << "##########################################" << endl;
    cout << "######## Gestion de Publicaciones ########" << endl;
    cout << "##########################################\n" << endl;
}
int main() {
    vector<Post*> publicaciones;
    TextPost t("hola");
    cout << t;

    int opc, opc2;
    do{
        system("cls");
        encabezado();
        cout << "\n-Menu:\n" << endl;
        cout << "1. Crear publicacion" << endl;
        cout << "2. Mostrar publicaciones segun tipo de publicacion" << endl;
        cout << "3. Editar publicacion" << endl;
        cout << "4. Agregar like a publicacion" << endl;
        cout << "5. Agregar comentario a publicacion" << endl;
        cout << "6. Agregar etiqueta a publicacion" << endl;
        cout << "7. Eliminar publicacion" << endl;
        cout << "8. Salir\n" << endl;
        cout << " -Que desea realizar?" << endl;
        cout << ">>";
        cin >> opc;
        system("cls");
        if (opc == 1){
            encabezado();
            cout <<"\tCrear publicacion"<<endl;
            cout <<"-Seleccione el tipo de publicacion desea crear:"<<endl;
            cout << "1. TextPost" << endl;
            cout << "2. QuotePost" << endl;
            cout << "3. TaggedTextPost" << endl;
            cout << "4. PhotoPost" << endl;
            cout << "5. VideoPost" << endl;
            cout << "6. TaggedPhotoPost" << endl;
            cout << "7. TaggedVideoPost" << endl;
            cin >> opc2;
            if (opc2==1){
                publicaciones.emplace_back("help");
            }
            else if (opc==2){}
            else if (opc==3){}
            else if (opc==4){}
            else if (opc==5){}
            else if (opc==6){}
            else if (opc==7){}
        }
        else if (opc == 2){
            encabezado();
            cout <<"\tMostrar publicaciones segun tipo de publicacion"<<endl;
            cout << "1. PhotoPost\n2. VideoPost\n3. QuotePost\n4.p\n5.p"<<endl;
        }
        else if (opc == 3){
            encabezado();
            cout << "Editando publicacion";
            cout << "Cual publicacion desea editar";
            cout << "1.p\n2.p\n3.p\n4.p\n5.p"<<endl;
            cin >> opc2;
            if(opc2==1){}
            else if(opc2==2){}
            else if(opc2==3){}
            else if(opc2==4){}
            else if(opc2==5){}
            else {cout << "--Digito una opcion incorrecta.--"<<endl;}

        }
        else if (opc == 4){
            encabezado();
            cout << "agregar like a la publicacion: ";
            cout << "1.p\n2.p\n3.p\n4.p\n5.p"<<endl;
        }
        else if (opc == 5){
            encabezado();
            cout << "agregar comentario a la publicacion: ";
            cout << "1.p\n2.p\n3.p\n4.p\n5.p"<<endl;
            cin >> opc2;
            if (opc2 == 1){}
            else if (opc2 == 2){}
            else if (opc2 == 3){}
            else if (opc2 == 4){}
            else if (opc2 == 5){}
            else if (opc2 == 5){}
        }
        else if (opc == 6){encabezado();}
        else if (opc == 7){encabezado();}
        else if (opc == 8){ cout << "--Hasta pronto.--"<<endl; }
        else { cout << "--Digito una opcion incorrecta.--"<<endl; }
    } while (opc!=8);

    return 0;
}
