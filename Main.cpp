#include <iostream>
#include "QuickSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include <fstream>
#include <stdlib.h>

void decrescente(int vetNumeros[],int);
void embaralhado(int vetNumeros[],int);
void calcularEsalvar(float quickCom,float quickTro,float shellCom,float shellTro,float mergeCom,float mergeTro,float heapCom,float heapTro,string modo, int quantOrd, float & maiorCom, float & maiorTro);

using namespace std;

int main(){
    ofstream clearResultados ("Resultados.txt",ios::trunc);
    clearResultados.close();
    int vetNumeros[10000],vetNumerosAux[10000], ordem, quantOrd;
    string diretorio, modo = "";
    char ch,opcao;
    string str;
    cout << "\nEscreva o diretorio do arquivo(completo), para pegar os valores do vetor: ";
    getline(cin,diretorio);
    ifstream numeros(diretorio);
    if(!numeros){
        cout << "\ndiretorio nao encontrado";
        exit(1);
    }
    do{
        cout << "\nQual a quantidade de valores que voce quer ordenar: ";
        cin >> quantOrd;
        for(int i=0; i<quantOrd; i++){
            while(numeros.get(ch) and ch != '\n'){
                str += ch;
            }
            vetNumeros[i] = atoi(str.c_str());
            str = "";
        }
        numeros.close();
        cout << "\nComo voce quer o vetor: \n1) Ordem crescente \n2) Ordem decrescente \n3) Aleatorio\nOpcao: ";
        cin >> ordem;
        if(ordem == 1){
            modo = "Crescente";
        }
        if(ordem == 2){
            decrescente(vetNumeros,quantOrd);
            modo = "Decrescente";
        }
        if(ordem == 3){
            embaralhado(vetNumeros,quantOrd);
            modo = "Embaralhado";
        }
        for(int i=0;i<quantOrd;i++)
            vetNumerosAux[i] = vetNumeros[i];
        float quickCom=0,quickTro=0,shellCom=0,shellTro=0,mergeCom=0,mergeTro=0,heapCom=0,heapTro=0;
        quickSort(vetNumeros,0,quantOrd,quickCom,quickTro);
        for(int i=0;i<quantOrd;i++)
            vetNumeros[i] = vetNumerosAux[i];
        shellSort(vetNumeros,quantOrd,shellCom,shellTro);
        for(int i=0;i<quantOrd;i++)
            vetNumeros[i] = vetNumerosAux[i];
        mergeSort(vetNumeros,0,quantOrd,mergeCom,mergeTro);
        for(int i=0;i<quantOrd;i++)
            vetNumeros[i] = vetNumerosAux[i];
        heapSort(vetNumeros,quantOrd,heapCom,heapTro);
        float maiorCom, maiorTro;
        calcularEsalvar(quickCom,quickTro,shellCom,shellTro,mergeCom,mergeTro,heapCom,heapTro,modo,quantOrd,maiorCom,maiorTro);
        cout << "\n\nFeito!\n\nQuer fazer outro teste (S/N)? ";
        cin.ignore();
        cin.get(opcao);
    }while(toupper(opcao) != 'N');
}

void decrescente(int vetNumeros[], int quantOrd){
    for(int i = 0; i<quantOrd/2; i++){
        swap(vetNumeros[i],vetNumeros[quantOrd-1-i]);
    }
}

void embaralhado(int vetNumeros[], int quantOrd){
    for (int i = 0; i < quantOrd; i++)
    {
        int r = rand() % quantOrd;
        int temp = vetNumeros[i];
        vetNumeros[i] = vetNumeros[r];
        vetNumeros[r] = temp;
    }
}

void calcularEsalvar(float quickCom,float quickTro,float shellCom,float shellTro,float mergeCom,float mergeTro,float heapCom,float heapTro,string modo, int quantOrd, float & maiorCom, float & maiorTro){
    maiorCom = quickCom;
    if(maiorCom < shellCom)
        maiorCom = shellCom;
    if(maiorCom < mergeCom)
        maiorCom = mergeCom;
    if(maiorCom < heapCom)
        maiorCom = heapCom;
    maiorTro = quickTro;
    if(maiorTro < shellTro)
        maiorTro = shellTro;
    if(maiorTro < mergeTro)
        maiorTro = mergeTro;
    if(maiorTro < heapTro)
        maiorTro = heapTro;

    ofstream resultados ("Resultados.txt", ios::app);
    resultados<<"\n\n|Quick Sort|\n" << quantOrd << " valores ordenados."
    << " Modo: " << modo
    << "\nComparacoes: " << (quickCom/maiorCom)*100 << "%\nTrocas: " << (quickTro/maiorTro)*100
    <<"%\n\n|Shell Sort|\n" << quantOrd << " valores ordenados."
    << " Modo: " << modo
    << "\nComparacoes: " << (shellCom/maiorCom) * 100 << "%\nTrocas: " << (shellTro/maiorTro) * 100
    <<"%\n\n|Merge Sort|\n" << quantOrd << " valores ordenados."
    << " Modo: " << modo
    << "\nComparacoes: " << (mergeCom/maiorCom)*100 << "%\nTrocas: " << (mergeTro/maiorTro)*100
    <<"%\n\n|Heap Sort|\n" << quantOrd << " valores ordenados."
    << " Modo: " << modo
    << "\nComparacoes: " << (heapCom/maiorCom)*100 << "%\nTrocas: " << (heapTro/maiorTro)*100
    << "%\n______________________________________________________________";
    resultados.close();
}