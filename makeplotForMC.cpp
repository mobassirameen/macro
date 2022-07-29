#include<iostream>
#include "TROOT.h"
#include "TObject.h"
#include "TProfile.h"
#include "TFile.h"
#include "TTree.h"
#include "math.h"
#include "TH1.h"
#include<vector>

void makeplotForMC(){

    gStyle->SetPadLeftMargin(0.18);
    gStyle->SetPadRightMargin(0.14);
    gStyle->SetPadBottomMargin(0.10);
    gStyle->SetPadTopMargin(0.10);
    gStyle->SetOptStat(1111);
    gStyle->SetHistLineWidth(2);
    gStyle->SetLabelFont(132,"xyz");
    gStyle->SetLabelSize(0.04,"xyz");
    gStyle->SetTitleFont(132,"xyz");
    gStyle->SetTitleSize(0.04,"xyz");
    gStyle->SetLabelOffset(0.01,"xyz");
    gStyle->SetNdivisions(510,"xyz");


   //TFile *file = new TFile ("Rootuple_BsToJPsiphi_2018_MiniAOD.root");
   //TFile *file = new TFile ("FlatNtuple_pvtMCBsPi.root");
   //TFile *file = new TFile ("/Users/mohammadmobassirameen/Desktop/BcToBsPi-analysis/GenLevel-BsPi/29Apr2022_FlatNtuple_pvtMCBsPi_.root");
   //TFile *file = new TFile ("/Users/mohammadmobassirameen/Desktop/BcToBsPi-analysis/BDT_BcToBsPi/bdtsamples/MCSample/PvtMC-BsPi_FlatNtuple_07May2022.root");
   TFile *file = new TFile ("/Users/mohammadmobassirameen/Desktop/BcToBsPi-NTuples/pvtMCSamples/PvtMC-BsPi_FlatNtuple_28July2022.root");
   TDirectory *dir = (TDirectory*)file->Get("rootuple");
   TTree *t1 = (TTree*)dir->Get("ntuple");

   vector<double> *Bc_mass = 0;
   vector<double> *B_mass = 0;
   vector<double> *B_J_mass = 0;
   vector<double> *B_phi_mass = 0;

   TBranch * b_Bc_mass;
   TBranch * b_B_mass;
   TBranch * b_B_J_mass;
   TBranch * b_B_phi_mass;

   t1->SetBranchAddress("Bc_mass", &Bc_mass, &b_Bc_mass);
   t1->SetBranchAddress("B_mass", &B_mass, &b_B_mass);
   t1->SetBranchAddress("B_J_mass", &B_J_mass, &b_B_J_mass);
   t1->SetBranchAddress("B_phi_mass", &B_phi_mass, &b_B_phi_mass);

   
   TH1F *h1 = new TH1F("h1","", 100, 4.92, 6.06 );
   TH1F *h2 = new TH1F("h2","", 100, 0.98, 1.08 );
   TH1F *h3 = new TH1F("h3","", 100, 2.87, 3.30 );
   TH1F *h4 = new TH1F("h4","", 100, 5.7, 6.9 );
    
   int nentries = (int)t1->GetEntries();
   
   //cout << nentries << endl;
 
    for ( int i = 0; i<nentries; i++)
    {
     
      b_Bc_mass->GetEntry(i);
      b_B_mass->GetEntry(i);
      b_B_J_mass->GetEntry(i);
      b_B_phi_mass->GetEntry(i);

      for(int j = 0; j< B_phi_mass->size(); j++)
	  {
          double Bcmass = (*Bc_mass)[j];
          double Bsmass = (*B_mass)[j];
          double BJPsimass = (*B_J_mass)[j];
          double Bphimass = (*B_phi_mass)[j];
          h1->Fill(Bsmass);
          h2->Fill(Bphimass);
          h3->Fill(BJPsimass);
          h4->Fill(Bcmass);
	  }
    }

    TCanvas* canvas1 = new TCanvas("canvas1", "", 800, 600);
    TCanvas* canvas2 = new TCanvas("canvas2", "", 800, 600);
    TCanvas* canvas3 = new TCanvas("canvas3", "", 800, 600);
    TCanvas* canvas4 = new TCanvas("canvas4", "", 800, 600);
    

    
    h1->GetYaxis()->SetTitleOffset(1.50);
    //h1->GetYaxis()->CenterTitle(true);
    h1->GetYaxis()->SetTitle("Events");
    h1->GetXaxis()->SetTitleOffset(1.15);
    h1->GetXaxis()->SetLabelOffset(0.02);
    h1->GetXaxis()->SetTitle("m_{J/#psi#phi} [GeV]");
    //h1->GetXaxis()->CenterTitle(true);
    h1->GetXaxis()->SetTitleSize(0.042);
    h1->GetYaxis()->SetTitleSize(0.042);
    
    h2->GetYaxis()->SetTitleOffset(1.50);
    //h2->GetYaxis()->CenterTitle(true);
    h2->GetYaxis()->SetTitle("Events");
    h2->GetXaxis()->SetTitleOffset(1.15);
    h2->GetXaxis()->SetLabelOffset(0.02);
    h2->GetXaxis()->SetTitle("m_{K^{+}K^{-}} [GeV]");
    //h2->GetXaxis()->CenterTitle(true);
    h2->GetXaxis()->SetTitleSize(0.042);
    h2->GetYaxis()->SetTitleSize(0.042);
    
    h3->GetYaxis()->SetTitleOffset(1.50);
    //h3->GetYaxis()->CenterTitle(true);
    h3->GetYaxis()->SetTitle("Eventss");
    h3->GetXaxis()->SetTitleOffset(1.15);
    h3->GetXaxis()->SetLabelOffset(0.02);
    h3->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} [GeV]");
    //h3->GetXaxis()->CenterTitle(true);
    h3->GetXaxis()->SetTitleSize(0.042);
    h3->GetYaxis()->SetTitleSize(0.042);
    
    h4->GetYaxis()->SetTitleOffset(1.50);
    //h4->GetYaxis()->CenterTitle(true);
    h4->GetYaxis()->SetTitle("Eventss");
    h4->GetXaxis()->SetTitleOffset(1.15);
    h4->GetXaxis()->SetLabelOffset(0.02);
    h4->GetXaxis()->SetTitle("m_{B_{s} #pi} [GeV]");
    //h3->GetXaxis()->CenterTitle(true);
    h4->GetXaxis()->SetTitleSize(0.042);
    h4->GetYaxis()->SetTitleSize(0.042);
    
    
    
    canvas1->cd();
    h1->Draw();
    
    canvas2->cd();
    h2->Draw();
    
    canvas3->cd();
    h3->Draw();
    
    canvas4->cd();
    h4->Draw();
    
    //TLegend *legend = new TLegend(.75,.80,.95,.95);
    //TLegend *legend = new TLegend(.80,.80,.62,.88);
    //legend->SetFillStyle(0);
    //legend->SetLineWidth(0);
    //legend->AddEntry(h2,"Data");
    //legend->SetLineColor(0);
    //legend->Draw("E1");
    
    
    //auto *cms1 = new TLatex(5.0, 49050, "#bf{CMS} #it{Simulations}, #sqrt{#f{s}} = #bf{13 TeV}");
    //cms1->SetNDC(false);
    //cms1->SetTextColor(12);
    //cms1->SetTextFont(42);
    //cms1->SetTextSize(0.055);
    //cms1-> Draw();
    
    //TPaveText *pt = new TPaveText(0.20,0.7,0.5,0.87,"NDC");
                     //note the strict C++ syntax (not required for interactive CINT)
                     // NDC sets the coordinates relative to the dimensions of the pad
                     // useful if you might change the layout of your histos
    //pt->SetFillColor(0);  //text now is black on white
    //pt->SetTextSize(0.04);
    //pt->SetTextAlign(12);
    //pt->SetLineColor(0);

    //pt->AddText("Whatever you want");
    //pt->AddText("#bf{CMS} #it{Simulations}, #sqrt{#f{s}} = #bf{13 TeV}");
    //pt->AddText("#bf{CMS} #it{Simulations}");

    //pt->Draw();       //to draw your text object
    
    
    //TLegend* leg = new TLegend(0.1,0.5,0.38,0.9);
    //leg->SetFillStyle(0);
    //leg->SetLineWidth(0);
    //leg->SetHeader(Form("Category %d",cate));
    //leg->AddEntry(h1,"Simluation","EP");
    //leg->AddEntry(frame->findObject("t_pdf_sig"),"Fit","L");
    //leg->Draw();
    
    //canvas->Print("task2_1.pdf");
    
    
    //canvas->Print();

}
