import sympy as sp
from decimal import Decimal, ROUND_DOWN
from sympy.parsing.sympy_parser import parse_expr

'''
    Aproximación del valor de una función mediante Serie de MacLaurin
'''

class AproxSerieMclaurin:
    def __init__(self):
        pass

    def truncar(self, num, decimales):
        return Decimal(str(num)).quantize(Decimal(f"1.{'0' * decimales}"), rounding=ROUND_DOWN)

    def e_t(self, valor_verdadero: float, valor_aprox: float):
        '''
            Calcula el Error Porcentual Verdadero
        '''
        e_t = (( valor_verdadero - valor_aprox ) / valor_verdadero) * 100
        return e_t

    def e_a(self, aprox_actual: float, aprox_anterior: float):
        '''
            Calcula el Error Normalizado
        '''
        e_a = (( aprox_actual - aprox_anterior ) / aprox_actual) * 100
        return e_a

    def e_s(self, c: int) -> float:
        '''
            Calcula el Error Estándar.
            Parámetros:
            n -> Número de cífras significativas
        '''
        e_s = 0.5 * 10**(2-c)
        print("e_a:",e_s)
        return (0.5 * 10**(2-c))

    def cumpleCondicion(self, e_a: float, e_s: float):
        '''
            Verfica si cumple la condición.
            Parámetros: 
            e_a -> Error Normalizado,
            e_s -> Error Estándar
        '''
        try:
            n_abs = abs(e_a)
            if n_abs == 0:
                return False
            return ( n_abs < e_s )
        except Exception as e:
            print(f"Error: {e}")

    def parse_f(self, f: any, gui=False):
        '''
            Recibe la función como string y la convierte a una función simbólica de Sympy.
        '''
        if not gui:
            entrada = input("\nIngresa una función en términos de x: ")

            # Convertir el string a una función simbólica
            f = parse_expr(entrada, transformations="all")
        else:
            # Convertir el string a una función simbólica
            f = parse_expr(f, transformations="all")
        
        return f


    def serieMacLaurin(self, f: any, x_value: any, c: int):
        '''
            Calcula la aproximación mediante la serie de McLaurin.\n
            Parámetros:\n
            \tf -> Función
            \tx_value -> Valor de x
            \tc -> Número de cifras significativas
            Retorno:\n
            \tn -> Número de términos necesarios para hacer el cálculo para la cantidad c de cifras significativas.
            \tall_Res -> Todas las aproximaciones con cada cantidad de términos.
            \tall_e_t -> Todos los errores verdaderos para cada término.
            \tall_e_a -> Todos los errores normalizados para cada término.
            \tf_serie_Mclaurin -> Funcion serie de McLaurin equivalente a la inicial.
            \taprox_s_m -> Valor de la aproximación calculado de la f_serie_Mclaurin.
        '''
        try:
            if f and x_value and c:
                print("\nFuncion:",f)
                x = sp.Symbol('x') # Variable
                real = f.subs(x,x_value)
                print("Valor Real:",real)
                print("Valor Real es numerico:", real.is_number)
                if not real.is_number:
                    return
                all_Res = []
                all_e_t = []
                all_e_a = []
                res = 0
                anterior = 0
                n = 0
                primer_aprox = True
                e_standard = self.e_s(c)
                f_serie_Mclaurin = 0
                f_polinomio = 0

                while primer_aprox or not self.cumpleCondicion(self.e_a(res,anterior),e_standard):
                    derivada = sp.diff(f,x,n) # Derivada enecima de la funcion
                    derivada_evaluada = derivada.subs(x,0).evalf() # Evalua la derivada enecima en cero
                    # print(f'Derivada {n}: ', derivada, "Sust: ", derivada_evaluada)
                    anterior = res # Guarda la aproximacion anterior
                    res += ((derivada_evaluada * x_value**n) / sp.factorial(n) ) # Almacena el valor de la aproximacion
                    all_Res.append(res) # Almacena todas las aproximaciones
                    all_e_t.append(self.e_t(real,res)) # Almacena todos los errores verdaderos

                    f_polinomio = ( x**n / sp.factorial(n) )
                    f_serie_Mclaurin += (derivada_evaluada * f_polinomio) # Almacena la serie de Mclaurin
                    
                    if n >= 1: # Esto se hace porque para la primera aproximacion no se le puede calcular un error normalizado
                        primer_aprox = False
                        all_e_a.append(self.e_a(res,anterior))

                    n += 1
                # print(all_Res)
                
                aprox_s_m = f_serie_Mclaurin.subs(x,x_value)
                print("Aproximación:", aprox_s_m)
                print("Serie McLaurin:", f_serie_Mclaurin)
                return n, all_Res, all_e_t, all_e_a, f_serie_Mclaurin, aprox_s_m
            else: 
                print("Faltan datos en serieMacLaurin()")
        except Exception as e:
            print(f"Error en serieMacLaurin(): {e}")

    def mostrarTabla(self, t: int, res: list, err_t: list, err_a: list, c: int):
        print("\nTérminos\tResultado\t e_t(%)\t\t e_a(%)")
        for e in range(t):
            if e == 0:
                print("  ",e+1,"\t\t",self.truncar(res[e],c),"\t\t",self.truncar(err_t[e],c))
            else:
                print("  ",e+1,"\t\t",self.truncar(res[e],c),"\t\t",self.truncar(err_t[e],c),"\t\t",self.truncar(err_a[e-1],c))
        print(f"El resultado de la aproximación es: {self.truncar(res[-1],c)}")

    def menu(self):
        while True:
            f = self.parse_f("")
            x = float(input("\nDigite el valor de X: "))
            c = int(input("\nDigite la cantidad de dígitos: "))
            t, res, err_t, err_a, f_s_m, a_f_s_m  = self.serieMacLaurin(f,x,c)
            if t and res and err_t and err_a and c:
                self.mostrarTabla(t,res,err_t,err_a,c)

# sm = AproxSerieMclaurin()
# sm.menu()

# x = sp.Symbol('x')
# derivada = sp.cos(x)  # Función coseno

# # Evaluar cos(π) con mayor precisión
# sust = derivada.subs(x, sp.pi).evalf()  # 50 dígitos de precisión
# print(sust)