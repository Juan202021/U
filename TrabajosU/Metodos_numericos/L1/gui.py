import dearpygui.dearpygui as dpg
import numpy as np
import sympy as sp
from serieMcLaurin import AproxSerieMclaurin as asm 

class App:
    def __init__(self):
        self.s_m = asm()
        self.mainWindow_width = 1200
        self.mainWindow_height = 950
        self.label_indent = 80
        self.button_indent = 530
        self.info_indent = 500
        self.input_width = 320
        self.tableCreated = False
        self.plotCreated = False

    def start(self):
        dpg.create_context()
        dpg.create_viewport(title="Aproximación por Serie de McLaurin", 
                                        width=self.mainWindow_width, height=self.mainWindow_height, 
                                        resizable=False)
        dpg.set_global_font_scale(1.5)  # Aumenta un 50% el tamaño del texto
        # fuente_grande = dpg.add_font(size=20)
        # dpg.bind_font(fuente_grande)
        
        self.data()  # Construimos la interfaz antes de iniciar Dear PyGui

        dpg.setup_dearpygui()
        dpg.show_viewport()
        dpg.start_dearpygui()
        dpg.destroy_context()

    def data(self):
        with dpg.window(width=self.mainWindow_width, 
                        height=self.mainWindow_height, 
                        no_resize=True, no_close=True, no_move=True,
                        no_collapse=True, tag="data", label="Ingrese los datos"):
            dpg.set_item_pos("data", (0, 0))

            with dpg.group(horizontal=True):
                with dpg.group(indent=self.label_indent):
                    dpg.add_text("")
                    dpg.add_text("Ingrese la función:", color=(173, 216, 230, 255)) #color=(255, 215, 0, 255)
                    dpg.add_text("Ingrese el valor de X:", color=(173, 216, 230, 255)) #color=(255, 255, 0, 255)
                    dpg.add_text("Ingrese la cantidad de dígitos:", color=(173, 216, 230, 255))
                    
                with dpg.group():
                    dpg.add_text("")
                    dpg.add_input_text(tag="input_f", width=self.input_width, 
                                        no_spaces=True, hint="Ej: exp(x), cos(x), sin(x)")
                    dpg.add_input_text(tag="input_x", width=self.input_width, 
                                        no_spaces=True, hint="No utilice coma, solo punto...")
                    dpg.add_input_int(tag="input_c", width=self.input_width)           

                with dpg.group():
                    dpg.add_text("")
                    dpg.add_button(label="Calcular", callback=self.mostrar_todo, 
                            tag="boton", width=200, height=50, indent=80)
                    dpg.add_text("")
                    dpg.add_text("", tag="info", indent=95, color=(255, 36, 0, 255))

            dpg.add_separator()

    def parse(self, f, x:str, c:int):
        try:
            f = self.s_m.parse_f(f,True)
            if "pi" in x:
                x = x.replace("pi",str(np.pi)) if "*" in x else x.replace("pi","*"+str(np.pi))
                x = eval(x)
            elif "e" in x:
                x = x.replace("e",str(np.e)) if "*" in x else x.replace("e","*"+str(np.e))
                x = eval(x)
                # x = float(x.replace("e",str(np.e)))
            else:
                x = float(x)
            c = int(c)
        except Exception as e:
            dpg.set_value("info", "Entrada Inválida.")
        return f, x, c

    def mostrar_todo(self):
        try:
            f = dpg.get_value("input_f")
            x = dpg.get_value("input_x")
            c = dpg.get_value("input_c")
            if f and x and c:
                f_p, x_p, c_p = self.parse(f,x,c)
                if x != x_p:
                    dpg.set_value("info", "")
                    f_s_m, a_s_m = self.mostrar_aprox(f_p,x_p,c_p)
                    if f_s_m and a_s_m:
                        self.mostrar_grafica(f, x_p, f_s_m, a_s_m)
            else:
                dpg.set_value("info", "Datos Incompletos.")
        except Exception as e:
            dpg.set_value("info", "Entrada Inválida")
            print("Error en mostrar_todo():",e)

    def mostrar_aprox(self, f, x, c):
        try:
            t, res, err_t, err_a, f_s_m, a_s_m = self.s_m.serieMacLaurin(f,x,c)

            if t and res and err_t and err_a and f_s_m and a_s_m:
                if self.tableCreated: 
                    # Eliminar si estaba renderizado anteriormente
                    children = dpg.get_item_children("contenedor_tabla", 1)  # Obtiene los hijos del contenedor
                    if children:
                        for child in children:
                            dpg.delete_item(child)  # Borra cada elemento

                        dpg.add_text("", parent="contenedor_tabla")
                        dpg.add_text("TABLA DE APROXIMACIONES", parent="contenedor_tabla", indent=450, color=(0, 255, 255, 255))
                        dpg.add_text("", parent="contenedor_tabla")
                        with dpg.table(header_row=True, 
                                        resizable=True, 
                                        borders_innerH=True, 
                                        borders_outerH=True, 
                                        borders_innerV=True, 
                                        borders_outerV=True, 
                                        tag="mi_tabla", 
                                        parent="contenedor_tabla"):
                            dpg.add_table_column(label="Términos", tag="h1")
                            dpg.add_table_column(label="Resultado", tag="h2")
                            dpg.add_table_column(label="Et(%)", tag="h3")
                            dpg.add_table_column(label="Ea(%)", tag="h4")
                                
                            for e in range(t):    
                                # Filas con valores
                                if e == 0:
                                    with dpg.table_row():
                                        dpg.add_text(str(e+1))
                                        dpg.add_text(str(res[e])) if e < (t - 1) else dpg.add_text(str(res[e]), color=(77, 255, 77, 255))
                                        dpg.add_text(str(err_t[e]))
                                else: 
                                    with dpg.table_row():
                                        dpg.add_text(str(e+1))
                                        dpg.add_text(str(res[e])) if e < (t - 1) else dpg.add_text(str(res[e]), color=(77, 255, 77, 255))
                                        dpg.add_text(str(err_t[e]))
                                        dpg.add_text(str(err_a[e-1]))
                        dpg.add_text(f"E_s:  {self.s_m.e_s(c)}", parent="contenedor_tabla", indent=(self.mainWindow_width - 400), color=(152, 255, 152, 255))

                else:
                    self.tableCreated = True
                    # Contenedor para la tabla
                    with dpg.child_window(tag="contenedor_tabla", width=self.mainWindow_width-20 , height=300, parent="data"):
                        dpg.add_text("")
                        dpg.add_text("TABLA DE APROXIMACIONES", indent=450, color=(0, 255, 255, 255))
                        dpg.add_text("")
                        with dpg.table(header_row=True, 
                                                    resizable=False, 
                                                    borders_innerH=True, 
                                                    borders_outerH=True, 
                                                    borders_innerV=True, 
                                                    borders_outerV=True, 
                                                    tag="mi_tabla"):
                            dpg.add_table_column(label="Términos", tag="h1")
                            dpg.add_table_column(label="Resultado", tag="h2")
                            dpg.add_table_column(label="Et(%)", tag="h3")
                            dpg.add_table_column(label="Ea(%)", tag="h4")
                                
                            for e in range(t):    
                                # Filas con valores
                                if e == 0:
                                    with dpg.table_row():
                                        dpg.add_text(str(e+1))
                                        dpg.add_text(str(res[e])) if e < (t - 1) else dpg.add_text(str(res[e]), color=(77, 255, 77, 255))
                                        dpg.add_text(str(err_t[e]))
                                else: 
                                    with dpg.table_row():
                                        dpg.add_text(str(e+1))
                                        dpg.add_text(str(res[e])) if e < (t - 1) else dpg.add_text(str(res[e]), color=(77, 255, 77, 255))
                                        dpg.add_text(str(err_t[e]))
                                        dpg.add_text(str(err_a[e-1]))
                        dpg.add_text(f"E_s:  {self.s_m.e_s(c)}", indent=(self.mainWindow_width - 400), color=(135, 206, 235, 255))

                return f_s_m, a_s_m
            else:
                print("No hay parámetros suficientes para mostrar la tabla en ( mostrar_aprox() ) ")
        except Exception as e:
            dpg.set_value("info", "Entrada Inválida")

    def mostrar_grafica(self, f, x_value, f_s_m, a_s_m):
        try:
            if f and x_value and f_s_m and a_s_m:
                x = np.linspace(-30, 30, 1200)
                punto_x = [x_value]  # Coordenada X del punto
                punto_y_aprox_s_m = [a_s_m]
                x_var = sp.Symbol('x')

                # Convertir la función simbólica en una función NumPy
                f_numeric = sp.lambdify(x_var, f_s_m, 'numpy')

                # Evaluar la función en todo el array de x
                f_serie_m = f_numeric(x)

                # f_serie_m = np.array([f_s_m.subs(x_var, val).evalf() for val in x], dtype=np.float64)

                if "sin" in f:
                    y = np.sin(x)
                    punto_y = [np.sin(x_value)]  # Coordenada Y del punto
                elif "cos" in f:
                    y = np.cos(x)
                    punto_y = [np.cos(x_value)]  # Coordenada Y del punto
                elif "exp" in f:
                    y = np.exp(x)
                    punto_y = [np.exp(x_value)]  # Coordenada Y del punto
                else:
                    print("Funcion no disponible")

                if not self.plotCreated:
                    dpg.add_separator(parent="data")
                    with dpg.plot(label="Gráfica", height=400, width=self.mainWindow_width-20, parent="data", tag="grafica",indent=500): #650
                        dpg.set_item_pos("grafica",(10,520)) #260
                        dpg.add_plot_legend(tag="leyenda", outside=True, location=dpg.mvPlot_Location_East)
                        dpg.add_plot_axis(dpg.mvXAxis, label="X", tag="x_axis")
                        dpg.add_plot_axis(dpg.mvYAxis, label="Y", tag="y_axis")
                        # Establecer límites iniciales
                        dpg.set_axis_limits("x_axis", -20, 20) if "sin" in f or "cos" in f else dpg.set_axis_limits("x_axis", -20, 20)
                        dpg.set_axis_limits("y_axis", -1.5, 1.5) if "sin" in f or "cos" in f else dpg.set_axis_limits("y_axis", -5, 30)
                        # Permitir zoom activando el ajuste automático después
                        # dpg.set_axis_limits_auto("x_axis")
                        # dpg.set_axis_limits_auto("y_axis")
                        # Dibujar series en el grafico
                        dpg.add_line_series(x, y, label=f, parent="y_axis", tag="serie_datos")
                        dpg.add_line_series(x, f_serie_m, label=f"Serie McLaurin de {f}", parent="y_axis", tag="serie_datos_McLaurin")
                        # Agregar un punto (scatter series)
                        dpg.add_scatter_series(punto_x, punto_y, label=f"P({x_value}, {f.replace("(x)","("+str(x_value)+")")})", parent="y_axis", tag="punto_valor_real")
                        dpg.add_scatter_series(punto_x, punto_y_aprox_s_m, label=f"A({x_value}, {str(a_s_m)})", parent="y_axis", tag="punto_aproximacion")
                    self.plotCreated = True
                else:
                    dpg.set_value("serie_datos", [x, y])  # Actualiza los datos de la serie
                    dpg.set_value("serie_datos_McLaurin", [x, f_serie_m])  # Actualiza los datos de la serie_mclaurin
                    dpg.set_value("punto_valor_real", [punto_x, punto_y]) # Actualiza los datos del punto_real
                    dpg.set_value("punto_aproximacion", [punto_x, punto_y_aprox_s_m]) # Actualiza los datos del punto_aprox
                    dpg.set_item_label("serie_datos", f)  # Cambia la etiqueta de la serie
                    dpg.set_item_label("serie_datos_McLaurin", f"Serie McLaurin de {f}")  # Cambia la etiqueta de la serie_mclaurin
                    dpg.set_item_label("punto_valor_real", f"P({x_value}, {f.replace("(x)","("+str(x_value)+")")})")  # Cambia la etiqueta del punto_real
                    dpg.set_item_label("punto_aproximacion", f"A({x_value}, {str(a_s_m)})")  # Cambia la etiqueta del punto_aprox
                    dpg.set_axis_limits("x_axis", -20, 20) if "sin" in f or "cos" in f else dpg.set_axis_limits("x_axis", -20, 20)
                    dpg.set_axis_limits("y_axis", -1.5, 1.5) if "sin" in f or "cos" in f else dpg.set_axis_limits("y_axis", -5, 30)
        except Exception as e:
            print("Error: ", e) 
            

# Ejecutar la aplicación
mi_app = App()
mi_app.start()
