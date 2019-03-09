class Map{
 public:
  
  Map(int);
  void showMap();    //show  map
  void findRoute1(); //first part of hw 
  void findRoute2(); //second part of hw
  //void findRoute3();
  void showRoute();  //show the rout
  //int fact(int);
 private:
  int N{};
  int d{};
  std::vector<std::vector<int>> map{}; // map
  std::vector<int> submap{};
  std::vector<std::vector<char>> route{};  //rout 
  std::vector<char> subroute{};
  bool flag{};
};
