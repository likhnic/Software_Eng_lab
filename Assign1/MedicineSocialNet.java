import java.util.ArrayList;
import java.util.Scanner;

public class MedicineSocialNet {
    
    // varaiable to store total number of entities
    static int ind=0;
    static int forid=1;
    public static void main(String[] args) {
        // array list to store all entities in one array (since unique Id 
        // is given we can always access with Id)
        ArrayList<Entities> entity_list= new ArrayList<Entities>();
        Scanner obj=new Scanner(System.in);
        int input;
        while(true){
            System.out.println("Press ");
            System.out.println("1 to Create, Delete or Print Entities ");
            System.out.println("2 to access Customer Menu ");
            System.out.println("3 to access Manufacturer Menu ");
            System.out.println("4 to access Shop Menu ");
            System.out.println("5 to Quit ");
            System.out.print(">");
            input=obj.nextInt();
            if(input==1){
                int subInput;
                System.out.println("---Press 1 to Create Entities");
                System.out.println("---Press 2 to Delete Entities");
                System.out.println("---Press 3 to Print Entities");
                System.out.print("--->");
                subInput=obj.nextInt();
                if(subInput==1){
                    Entities created=createEntity(obj,entity_list);
                    entity_list.add(created);
                    ind++;
                    forid++;
                    continue;
                }
                if(subInput==2){
                    deleteEntity(obj, entity_list);
                    continue;
                }  
                if(subInput==3){
                    printEntities(entity_list);
                    continue;
                }
                continue;
            }
            if(input==2){
                System.out.println("---List of Customer Id's are :");
                for(int i=0;i<ind;++i){
                    if(entity_list.get(i) instanceof Customers){
                        entity_list.get(i).printId();
                    }
                }
                System.out.print("---Enter your Id to Proceed : ");
                int inp_id=obj.nextInt();
                System.out.println("---Press 1 to Add an Order");
                System.out.println("---Press 2 to See all Purchases");
                System.out.print("--->");
                int subInput=obj.nextInt();
                if(subInput==1){
                    addOrder(obj, entity_list, inp_id);
                }
                if(subInput==2){
                    printOrders(entity_list,inp_id);
                }
                continue;
            }
            if(input==3){
                System.out.println("---List of Manufacturer Id's are :");
                for(int i=0;i<ind;++i){
                    if(entity_list.get(i) instanceof Manufacturer){
                        entity_list.get(i).printId();
                    }
                }
                int subInput;
                System.out.print("---Enter your Manufacturer Id to Proceed : ");
                int inp_id=obj.nextInt();
                System.out.println("---Press 1 to Add a Product");
                System.out.println("---Press 2 to See list of Products made");
                System.out.print("--->");
                subInput=obj.nextInt();
                System.out.println(subInput);
                if(subInput==1){
                    int index=findById(entity_list, inp_id);
                    Entities temp=new Product(obj, entity_list.get(index).id,-1);
                    ((Manufacturer) entity_list.get(index)).addProd(temp);
                    entity_list.add(temp);
                    ind++;
                    forid++;
                }
                if(subInput==2){
                    printProducts(entity_list, inp_id);
                }
                continue;
            }
            if(input==4){
                System.out.println("---List of Shop Id's are :");
                for(int i=0;i<ind;++i){
                    if(entity_list.get(i) instanceof Shop){
                        entity_list.get(i).printId();
                    }
                }
                int subInput;
                System.out.print("---Enter your Shop Id to Proceed : ");
                int inp_id=obj.nextInt();
                System.out.println("---Press 1 to See list of items in the Shop");
                System.out.println("---Press 2 to Add copies of a Product");
                System.out.print("--->");
                subInput=obj.nextInt();
                int indOfShop=findById(entity_list, inp_id);
                if(subInput==1){
                    entity_list.get(indOfShop).printProducts();
                }
                if(subInput==2){
                    addCopy(obj, entity_list, indOfShop);
                }
                continue;
            }
            else break;
        }
    }

    static Entities createEntity(Scanner obj,ArrayList<Entities> entity_list){
        System.out.println("------1 to Create Customer ");
        System.out.println("------2 to Create Manufacturer ");
        System.out.println("------3 to Create Shop ");
        System.out.println("------4 to Create Agent ");
        System.out.println("------5 to Create Product ");
        System.out.print("------>");
        int input=obj.nextInt();
        if(input==1){
            return new Customers(obj,forid);
        }
        if(input==2){
            return new Manufacturer(obj,forid);
        }
        if(input==3){
            return new Shop(obj,forid);
        }
        if(input==4){
            return new Agent(obj,forid);
        }
        System.out.println("Id's of Manufacturers : ");
        for(int i=0;i<ind;++i){
            if(entity_list.get(i) instanceof Manufacturer){
                entity_list.get(i).printId();
            }
        }
        Product created=new Product(obj,-1, forid);
        int manuInd=findById(entity_list,created.manufId);
        // if(manuInd==-1){
        //     System.out.println("No manufacturer found, Create one : ");
        //     entity_list.add(new Manufacturer(obj,created.manufId));
        //     manuInd=ind;
        //     ind++;
        //     forid++;
        // }
        ((Manufacturer)entity_list.get(manuInd)).addProd(created);
        return created;
    }
    
    // When Id is given returns the position(Index) of entity in list
    static int findById(ArrayList<Entities> entity_list,int id){
        for(int i=0;i<ind;++i){
            if(entity_list.get(i).id==id){
                return i;
            }
        }
        return -1;
    }

    // Function to delete entity 
    // will print the selected type of entitiy then ask Id to delete that element
    static void deleteEntity(Scanner obj, ArrayList<Entities> entity_list){

        System.out.println("------1 to Delete Customer ");
        System.out.println("------2 to Delete Manufacturer ");
        System.out.println("------3 to Delete Shop ");
        System.out.println("------4 to Delete Agent ");
        System.out.println("------5 to Delete Product ");
        System.out.print("------>");
        int input=obj.nextInt();
        if(input==1){
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Customers){
                    entity_list.get(i).printId();
                }
            }
        }
        if(input==2){
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Manufacturer){
                    entity_list.get(i).printId();
                }
            }
        }
        if(input==3){
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Shop){
                    entity_list.get(i).printId();
                }
            }
        }
        if(input==4){
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Agent){
                    entity_list.get(i).printId();
                }
            }
        }
        if(input==5){
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Product){
                    entity_list.get(i).printId();
                }
            }
        }
        System.out.print("------Enter Id to delete that Entity : ");
        int inpId=obj.nextInt();
        int inpInd=-1;
        for(int i=0;i<ind;++i){
            if(entity_list.get(i).id==inpId){
                inpInd=i;
                break;
            }
        }
        if(inpInd==-1)return;
        if(entity_list.get(inpInd) instanceof Product){
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Manufacturer){
                    ((Manufacturer)entity_list.get(i)).removeProd(inpId);
                }
            }
            for(int i=0;i<ind;++i){
                if(entity_list.get(i) instanceof Shop){
                    ((Shop)entity_list.get(i)).removeProd(inpId);
                }
            }
        }
        entity_list.remove(inpInd);
        ind--;
        return;
    }

    static void printEntities(ArrayList<Entities> entity_list){
        System.out.println("------List of Entities is : ");
        for(int i=0;i<ind;++i){
            entity_list.get(i).printId();
        }
    }

    static void printOrders(ArrayList<Entities> entity_list, int id){
        for(int i=0;i<ind;++i){
            if(id==entity_list.get(i).id && (entity_list.get(i) instanceof Customers)){
                entity_list.get(i).printProducts();
                break;
            }
        }
    }

    static void printProducts(ArrayList<Entities> entity_list, int id){
        for(int i=0;i<ind;++i){
            if(id==entity_list.get(i).id && (entity_list.get(i) instanceof Manufacturer)){
                entity_list.get(i).printProducts();
                break;
            }
        }
    }

    static int selectAgent(ArrayList<Entities> entity_list, int zipCode){
        int deliveries=1000000000;
        int agentId=-1;
        for(int i=0;i<ind;++i){
            if(entity_list.get(i) instanceof Agent){
                Agent agent=(Agent)entity_list.get(i);
                if(agent.delivered<deliveries && agent.zipCode==zipCode){
                    agentId=i;
                    deliveries=agent.delivered;
                }
            }
        }
        if(agentId!=-1)((Agent)entity_list.get(agentId)).delivered++;
        return agentId;
    }

    static void addOrder(Scanner obj,ArrayList<Entities> entity_list,int id){

        System.out.println("Available products : ");
        for(int i=0;i<ind;++i){
            if(entity_list.get(i) instanceof Product){
                entity_list.get(i).printId();
            }
        }
        System.out.print("Enter the Id of Product you want to buy : ");
        int prodId=obj.nextInt();
        int prodInd=findById(entity_list, prodId);
        int custInd=findById(entity_list, id);
        int custZip=((Customers)entity_list.get(custInd)).zipCode;
        Entities prod=entity_list.get(prodInd);
        for(int i=0;i<ind;++i){
            if(entity_list.get(i) instanceof Shop){
                Shop currShop=(Shop)entity_list.get(i);
                if(currShop.zipCode==custZip){
                    if(currShop.checkProduct(prod.id)!=-1){
                        int agentId=selectAgent(entity_list, custZip);
                        if(agentId!=-1){
                            ((Customers) entity_list.get(custInd)).addProd(prod);
                            System.out.println("Your Order is added and delivery agent Name is : " + entity_list.get(agentId).name+ " and Id is : "+entity_list.get(agentId).id);
                            currShop.removeDelivered(prod.id);
                            if(removeProd(entity_list, prodId)==0){
                                entity_list.remove(prodInd);
                                ind--;
                            }
                            return;
                        }
                    }
                }
            }
        }
        System.out.println("Order can't be added");
    }

    // if product with id is not availabe in any shop then remove that product from list
    static int removeProd(ArrayList<Entities> entity_list, int id){
        
        for(int i=0;i<entity_list.size();++i){
            if(entity_list.get(i) instanceof Shop){
                if(((Shop)entity_list.get(i)).checkProduct(id)!=-1)return 1;
            }
        }
        return 0;
    }

    // Adds copy to a shop by Id of product
    // If they product is not yet created, function will create product(Manufacturer must be created before hand)
    // and then adds to shop
    static void addCopy(Scanner obj,ArrayList<Entities> entity_list,int shopInd){
        System.out.println("Available products : ");
        for(int i=0;i<ind;++i){
            if(entity_list.get(i) instanceof Product){
                entity_list.get(i).printId();
            }
        }
        System.out.print("Enter Id of Product to add its copies : ");
        int prod_id=obj.nextInt();
        int prod_ind=findById(entity_list, prod_id);
        System.out.print("Enter number of copies to add : ");
        int numOfCopies=obj.nextInt();
        if(prod_ind==-1){
            // Product prod=new Product(obj, -1,prod_id);
            // entity_list.add(prod);
            // ind++;
            // forid++;
            // int manuInd=findById(entity_list, prod.manufId);
            // ((Manufacturer)entity_list.get(manuInd)).addProd(prod);
            // ((Shop) entity_list.get(shopInd)).addProdCopies(prod, numOfCopies);
            return;
        }
        Entities prod=entity_list.get(prod_ind);
        if(((Shop)entity_list.get(shopInd)).checkProduct(prod.id)==-1){
            ((Shop) entity_list.get(shopInd)).addProdCopies((Product) prod, numOfCopies);
            return;
        }
        ((Shop)entity_list.get(shopInd)).addToexisting(prod_id, numOfCopies);
    }
}

// Class which stores a pair and is used in Shop class 
// for storing products available in a shop
class Pair{
    Product prod;
    int copies=0;
    Pair(Product prod, int num){
        this.prod=prod;
        this.copies=num;
    }
}

class Entities{
    int id;
    String name;

    public Entities(Scanner obj,int Id){
        this.id=Id;
        System.out.print("Enter Name of the entity : ");
        this.name=obj.next();
    }

    void printId(){
        System.out.print(" Id : "+this.id);
        System.out.print(" Name : "+this.name);
    }

    void printProducts(){
        System.out.print(" ");
    }
}

class Customers extends Entities{

    int zipCode;
    ArrayList<Entities> prodList=new ArrayList<Entities>();
    int numOfProds=0;
    public Customers(Scanner obj, int id) {
        super(obj,id);
        System.out.print("Enter the Zip Code of Customer: ");
        this.zipCode=obj.nextInt();
    }

    void printProducts(){
        super.printProducts();
        System.out.println(" Number of products Purchased : "+this.numOfProds);
        if(this.numOfProds!=0)System.out.println(" Products Purchased : ");
        for(int i=0;i<this.numOfProds;++i){
            System.out.println("ID : "+prodList.get(i).id+" Product name : "+prodList.get(i).name);
        }
    }

    void printId(){
        super.printId();
        System.out.println("\tCustomer");
    }

    void addProd(Entities prod){
        numOfProds++;
        prodList.add(prod);
    }

}

class Manufacturer extends Entities{

    ArrayList<Entities> prodList=new ArrayList<Entities>();
    int num_prods=0;
    public Manufacturer(Scanner obj, int Id) {
        super(obj,Id);
    }

    void printProducts(){
        super.printProducts();
        if(num_prods==0){
            System.out.println("No products are Manufactured");
            return;
        }
        System.out.println("Products made are :");
        for(int i=0;i<num_prods;++i){
            prodList.get(i).printId();
        }
    }

    void printId(){
        super.printId();
        System.out.println("\tManufacturer");
    }

    void addProd(Entities prod){
        num_prods++;
        prodList.add(prod);
    }

    void removeProd(int Id){
        for(int i=0;i<prodList.size();++i){
            if(prodList.get(i).id==Id){
                prodList.remove(i);
                num_prods--;
                break;
            }
        }
    }
}

class Product extends Entities{

    int manufId;
    public Product(Scanner obj, int manuf, int Id) {
        super(obj,Id);
        if(manuf==-1){
            System.out.print("Enter the Id of Manufacturer of Product from above list : ");
            this.manufId=obj.nextInt();
        }
        else this.manufId=manuf;
    }

    void printId(){
        super.printId();
        System.out.println("\tProduct");
    }

}

class Shop extends Entities{
    
    int zipCode;
    ArrayList <Pair> prodInShop =new ArrayList <Pair> ();
    public Shop(Scanner obj,int id) {
        super(obj,id);
        System.out.print("Enter the Zip Code of Shop/Warehouse : ");
        this.zipCode=obj.nextInt();
    }
    void printId(){
        super.printId();
        System.out.println("\tShop");
    }

    int checkProduct(int id){
        for(int i=0;i<prodInShop.size();++i){
            if(id==prodInShop.get(i).prod.id && prodInShop.get(i).copies>0){
                return i;
            }
        }
        return -1;
    }

    void printProducts(){
        super.printProducts();
        if(prodInShop.size()!=0)System.out.println("Products in shop are : ");
        else System.out.println("There are no products in Shop, please add a product to see list");
        for(int i=0;i<prodInShop.size();++i){
            System.out.println("Id : "+prodInShop.get(i).prod.id+" Name : "+prodInShop.get(i).prod.name+" Copies : "+prodInShop.get(i).copies);
        }
    }

    void addProdCopies(Product prod,int copies){
        Pair prodPair=new Pair(prod,copies);
        prodInShop.add(prodPair);
    }

    void addToexisting(int id,int copies){
        for(int i=0;i<prodInShop.size();++i){
            if(prodInShop.get(i).prod.id==id){
                prodInShop.get(i).copies+=copies;
                break;
            }
        }
    }

    void removeDelivered(int id){
        for(int i=0;i<prodInShop.size();++i){
            if(id==prodInShop.get(i).prod.id && prodInShop.get(i).copies>1){
                prodInShop.get(i).copies--;
                return;
            }
            if(id==prodInShop.get(i).prod.id && prodInShop.get(i).copies==1){
                prodInShop.remove(i);
                return;
            }
        }
    }

    void removeProd(int Id){
        for(int i=0;i<prodInShop.size();++i){
            if(prodInShop.get(i).prod.id==Id){
                prodInShop.remove(i);
                return;
            }
        }
    }

}

class Agent extends Entities{

    int zipCode;
    int delivered=0;
    public Agent(Scanner obj,int id) {
        super(obj,id);
        System.out.print("Enter the Zip Code of Agent : ");
        this.zipCode=obj.nextInt();
    }
    void printId(){
        super.printId();
        System.out.println("\tAgent");
    }
}
