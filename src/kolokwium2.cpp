#include <iostream>
#include <string>
#include <vector>

class DirectoryOrFile {
 public:
  virtual void search(std::string name) = 0;
  virtual void check() = 0;
  virtual void open() = 0;
  virtual void select() = 0;
};

class Directory : public DirectoryOrFile {
  std::string name;
  std::vector<DirectoryOrFile*> filesOrDirs;

 public:
  Directory(std::string name, std::vector<DirectoryOrFile*> filesOrDirs) {
    this->name = name;
    this->filesOrDirs = filesOrDirs;
  }
  void search(std::string name) {
    for (auto& fileOrDir : filesOrDirs) {
      fileOrDir->search(name);
    }
  };
  void check() {
    std::cout << "typ pliku to "
              << "Directory" << std::endl;
  };
  void open() { std::cout << "otworzono folder " << name << std::endl; };
  void select() { std::cout << "zaznaczono folder " << name << std::endl; };
};

class CodeBlockFile : public DirectoryOrFile {
  std::string name;

 public:
  CodeBlockFile(std::string name) { this->name = name; }
  void search(std::string name) {
    if (this->name.find(name)) {
      std::cout << "znaleziono plik " << this->name << std::endl;
    }
  };
  void check() {
    std::cout << "typ pliku to "
              << "CodeBlockFile" << std::endl;
  }
  void open() { std::cout << "otworzono plik " << name << std::endl; }
  void select() { std::cout << "zaznaczono plik " << name << std::endl; }
};

class WordFile : public DirectoryOrFile {
  std::string name;

 public:
  WordFile(std::string name) { this->name = name; }
  void search(std::string name) {
    if (this->name.find(name)) {
      std::cout << "znaleziono plik " << this->name << std::endl;
    }
  };
  void check() {
    std::cout << "typ pliku to "
              << "WordFile" << std::endl;
  }
  void open() { std::cout << "otworzono plik " << name << std::endl; }
  void select() { std::cout << "zaznaczono plik " << name << std::endl; }
};

class AcrobatReaderFile : public DirectoryOrFile {
  std::string name;

 public:
  AcrobatReaderFile(std::string name) { this->name = name; }
  void search(std::string name) {
    if (this->name.find(name)) {
      std::cout << "znaleziono plik " << this->name << std::endl;
    }
  };
  void check() {
    std::cout << "typ pliku to "
              << "AcrobatReaderFile" << std::endl;
  }
  void open() { std::cout << "otworzono plik " << name << std::endl; }
  void select() { std::cout << "zaznaczono plik " << name << std::endl; }
};

int main() {
  DirectoryOrFile* wypracowanie = new WordFile("wypracowanie");
  DirectoryOrFile* documents = new Directory(
      "Documents", {wypracowanie, new AcrobatReaderFile("prezentacja")});

  DirectoryOrFile* desktop = new Directory("Desktop", {new CodeBlockFile("program")});
  DirectoryOrFile* fileSystem = new Directory("Home", {documents, desktop});

  fileSystem->search("wypracowanie");
  wypracowanie->open();
  wypracowanie->select();
  desktop->select();
  wypracowanie->check();
  desktop->check();
}