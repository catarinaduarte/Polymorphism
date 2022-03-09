#include <iostream>
#include <string>

using namespace std;

class Veiculo {
	private:
		string cor;
		string nome;
		int ano;

    public:
		Veiculo();
		void acelerar(double aumVel);
		void travar(double dimVel);
		double obterVelocidade();
		void setVelocidade(double v);
		double getVelocidade();
        virtual double calculaPreco();

	private:
		double velocidade;
};

Veiculo::Veiculo() {
}

void Veiculo::acelerar(double aumVel) {
    velocidade += aumVel;
}

void Veiculo::travar(double dimVel) {
	velocidade -= dimVel;
}

double Veiculo::obterVelocidade() {
    return velocidade;
}

void Veiculo::setVelocidade(double v)  {
    velocidade = v;
}

double Veiculo::getVelocidade() {
    return velocidade;
}

double Veiculo::calculaPreco() {
    return 100;
}

class VeiculoBasico : public Veiculo {
    private:
        bool retrovisorPassageiro;
        bool limpadorTraseiro;
        bool radioAMFM;

    public:
        virtual double calculaPreco();
};

double VeiculoBasico::calculaPreco() {
    return 1000;
}

class VeiculoLuxo : public Veiculo {
    private:
        bool direcaoHidraulica;
        bool mudancasAutomaticas;
        bool vidroEletrico;

    public:
        virtual double calculaPreco();
};

double VeiculoLuxo::calculaPreco() {
    return 10000;
}

class Concecionaria {
    public:
        void imprimePreco( Veiculo *v ) {
            cout << v->calculaPreco() << endl;
        }
};

int main (void)
{
    Concecionaria c = Concecionaria();
    Veiculo v = Veiculo();
    VeiculoBasico vb = VeiculoBasico();
    VeiculoLuxo vl = VeiculoLuxo();

    cout << "Veiculo " << v.calculaPreco() << endl;
    cout << "Veiculo básico " << vb.calculaPreco() << endl;
    cout << "Veiculo luxo " << vl.calculaPreco() << endl;

    // Polimorfismo
    c.imprimePreco(&v); // imprimir usando a calculaPreco do Veiculo
    c.imprimePreco(&vb); // imprimir usando a calculaPreco do VeiculoBasico
    c.imprimePreco(&vl); // imprimir usando a calculaPreco do VeiculoLuxo

}