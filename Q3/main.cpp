#include<iostream>
#include<string>
#include<vector>
#include<fstream>

int main()
{
  size_t i{0};
  int to_count{1};
  bool flag1{};
  bool flag2{};
  bool flag3{};
  std::string read{};
  std::vector<std::string> product_id{};
  std::vector<std::string> costomer_id{};
  std::vector<int> product_count{};
  std::vector<int> costomer_count{}; 
  std::vector<std::string> input{};
  std::vector<std::string> output{};
  std::vector<std::vector<std::string>> list{};
  //to read from file
  std::ifstream file{"db.txt"};
  while(file >> read)
    {
      if(i < 3)
	{
	  input.push_back(read);
	  i++;
	}
      else
	{
	  input.push_back(read);
	  list.push_back(input);
	  input.clear();
	  i = 0;
	}
    }
  //to find the outputfile
  for(size_t i{ 0 } ; i < list.size() ; i++)
    {
      flag1 = true;
      if(i == 0)
	{
	  output.push_back(list[0][0]);
	  product_id.push_back(list[0][2]);
	  costomer_id.push_back(list[0][3]);
	  product_count.push_back(to_count);
	  costomer_count.push_back(to_count);
	}
      else
	{
	  for(size_t j{ 0 } ; j < output.size() ;j++)
	    if(list[i][0] == output[j])
	      {
		flag2 = false;
		flag3 = false;
		for(size_t k{ 0 } ; k < product_id.size() ;k++)
		  {
		    if(list[i][2] == product_id[k])
		      k=product_id.size();
		    else
		      {
			flag2 = true;
			product_id.push_back(list[i][2]);
		      }
		  }
		if(flag2)
		      {
			product_count[j]++;
		      }
		for(size_t k{ 0 } ; k < costomer_id.size() ;k++)
		  {
		    if(list[i][3] == costomer_id[k])
		      k = costomer_id.size();
		    else
		      {
			flag3 = true;
			costomer_id.push_back(list[i][3]);
		      }
		  }
		if(flag3)
		      {
			costomer_count[j]++;
		      }
		flag1 = false;
	      }
	  if(flag1)
	    {
	      output.push_back(list[i][0]);
	      product_count.push_back(to_count);
	      costomer_count.push_back(to_count);
	      product_id.clear();
	      costomer_id.clear();
	      product_id.push_back(list[i][2]);
	      costomer_id.push_back(list[i][3]);
	    }
	}
     }
  for(size_t i{}; i < output.size() ; i++)
    {
      std::cout << output[i] << "] " << product_count[i]  << " ";
      std::cout << costomer_count[i] << std::endl;
    }
  std::ofstream outlistfile ("dbnew.txt");
  for(size_t i{}; i < output.size() ; i++)
    {
      outlistfile << output[i] << "] " << product_count[i]  << " ";
      outlistfile << costomer_count[i] << std::endl;
    }
  outlistfile.close();
  return 0;
}
