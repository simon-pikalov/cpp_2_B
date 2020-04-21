#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;




TEST_CASE("Test add methods."){
	family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");


    SUBCASE("Test add to already exist place in tree "){
        CHECK_THROWS(T.addFather("Yosef","Yaakov")); 
        CHECK_THROWS(T.addMother("Yosef", "Rachel"));
        CHECK_THROWS(T.addFather("Yaakov", "Isaac")); 
        CHECK_THROWS(T.addMother("Yaakov", "Rivka"));
        CHECK_THROWS(T.addFather("Isaac", "Avraham"));
        CHECK_THROWS(T.addFather("Avraham", "Terah"));
        CHECK_THROWS(T.addFather("Yosef","a")); 
        CHECK_THROWS(T.addMother("Yosef", "av"));
        CHECK_THROWS(T.addFather("Yaakov", "avb")); 
        CHECK_THROWS(T.addMother("Yaakov", "vss"));
        CHECK_THROWS(T.addFather("Isaac", "sdd"));
        CHECK_THROWS(T.addFather("Avraham", "sdd"));

    }

        SUBCASE("add to unexist person in tree "){
        CHECK_THROWS(T.addFather("asd","Yaakov")); 
        CHECK_THROWS(T.addMother("asdas", "Rachel"));
        CHECK_THROWS(T.addFather("sad", "Isaac")); 
        CHECK_THROWS(T.addMother("sdas", "Rivka"));
        CHECK_THROWS(T.addFather("fdsf", "Avraham"));
        CHECK_THROWS(T.addFather("dasd", "Terah"));
        CHECK_THROWS(T.addFather("sads","a")); 
        CHECK_THROWS(T.addMother("sada", "av"));
        CHECK_THROWS(T.addFather("sad", "avb")); 
        CHECK_THROWS(T.addMother("dfg", "vss"));
        CHECK_THROWS(T.addFather("fdg", "sdd"));
        CHECK_THROWS(T.addFather("sdf", "sdd"));

    }
     

    SUBCASE("Tedt from main ."){
            CHECK(T.find("father") == "Yaakov"); 
            CHECK(T.find("mother") == "Rachel"); 
            CHECK(T.find("grandfather") == "Isaac"); 
            CHECK(T.find("great-grandfather") == "Avraham"); 
            CHECK(T.find("grandmother") == "Rivka"); 
            CHECK(T.find("great-great-grandfather") == "Terah"); 
            CHECK((T.father)->find("mother") == "Rivka"); 
            CHECK((T.father)->find("father") == "Isaac");
            CHECK(T.find("father") == "Yaakov"); 
            CHECK(T.relation("Yaakov") == "father");
            CHECK(T.relation("Yaakovs") == "unrelated");   
            CHECK(T.relation("Rachel") == "mother");
            CHECK(T.relation("Rachels") == "unrelated");  
            CHECK(T.relation("Rivka") == "grandmother");
            CHECK(T.relation("Rivkas") == "unrelated");   
            CHECK(T.relation("Avraham") == "great-grandfather");
            CHECK(T.relation("Avrahams") == "unrelated");   
            CHECK(T.relation("Terah") == "great-great-grandfather");
            CHECK(T.relation("Terah") == "unrelated");   
            CHECK(T.relation("Tesrah") == "unrelated"); 
            CHECK(T.relation("Yosef") == "me");
            CHECK(T.relation("Yossef") == "unrelated");
            CHECK((T.father)->relation("Rivka") == "mother"); 
            CHECK((T.father)->relation("Isaac") == "father");
            CHECK((T.father)->relation("mother") == "Rivka"); 
            CHECK((T.father)->relation("Avraham") == "grandfather");
            CHECK((T.father)->relation("Terah") == "great-great-grandfather"); 
            CHECK((T.father)->relation("father") == "unrelated");
            CHECK((T.father)->relation("mother") == "unrelated"); 
            CHECK((T.father)->relation("me") == "unrelated");
            CHECK((T.father)->relation("you") == "unrelated"); 
            CHECK((T.father)->relation("yosef") == "unrelated");
            CHECK((T.father)->relation("Rachel") == "unrelated"); 
            CHECK((T.father)->relation("Yaakov") == "me");
            

    
    }


    Tree t3("A");
    t3.addFather("1","2")
    .addFather("2","3")
    .addFather("3","4")
    .addFather("4","5")
    .addFather("5","6")
    .addFather("6","7")
    .addFather("7","8")
    .addFather("8","9")
    .addFather("10","11")
    .addFather("11","12")
    .addFather("12","13")
    .addFather("13","14")
    .addFather("14","15")
    .addFather("15","16")
    .addFather("16","17")
    .addFather("17","18")
    .addFather("18","19")
    .addFather("19","20")
    .addFather("20","21")
    .addFather("21","22")
    .addFather("22","23")
    .addFather("10","11")
    .addFather("11","12")
    .addFather("12","13")
    .addFather("13","14")
    .addFather("14","15")
    .addFather("15","16")
    .addFather("16","17")
    .addFather("17","18")
    .addFather("18","19")
    .addFather("19","20")
    .addFather("20","21")
    .addFather("21","22")
    .addFather("22","23")
    .addFather("23","24")
    .addFather("24","25")
    .addFather("25","26")
    .addFather("26","27")
    .addFather("27","28")
    .addFather("28","29")
    .addFather("29","30")
    .addFather("30","31")
    .addFather("31","32")
    .addFather("32","33")
    .addFather("33","34")
    .addFather("34","35")
    .addFather("35","36")
    .addFather("36","37")
    .addFather("37","38")
    .addFather("38","39")
    .addFather("39","40")
    .addFather("40","41")
    .addFather("41","42")
    .addFather("42","43")
    .addFather("43","44")
    .addFather("44","45")
    .addFather("45","46")
    .addFather("46","47")
    .addFather("47","48")
    .addFather("48","49")
    .addFather("49","50")
    .addFather("50","51")
    .addFather("51","51");
    SUBCASE("Test very long relation of numberXgreat-grandfather"){
        CHECK(t3.relation("1") == "me");
        CHECK(t3.relation("2") == "father");
        CHECK(t3.relation("3") == "grandfather");
        CHECK(t3.relation("4") == "great-grandfather");
        CHECK(t3.relation("5") == "great-great-grandfather");
        CHECK(t3.relation("6") == "great-great-great-grandfather");
        CHECK(t3.relation("7") == "great-great-great-great-grandfather");
        CHECK(t3.relation("8") == "great-great-great-great-great-grandfather");
        CHECK(t3.relation("9") == "great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("10") == "great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("11") == "great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("12") == "great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("13") == "great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("14") == "great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("15") == "great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("16") == "great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("17") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("18") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("19") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("20") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("21") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("22") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("23") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("24") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("25") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("26") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("27") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("28") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("29") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("30") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("31") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("32") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grat-great-grandfather");
        CHECK(t3.relation("33") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("34") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("35") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("36") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("37") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("38") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("39") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("40") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("41") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("42") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("44") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("45") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("46") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("47") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("48") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("49") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("50") == "great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-great-grandfather");

    }
}


