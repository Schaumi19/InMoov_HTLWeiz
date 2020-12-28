using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using System.Threading;
using System.Speech.Recognition;
using System.Speech.Synthesis;


namespace SerialPortTerminal
{
    public partial class Form1 : Form
    {
        private Thread control;
        public Form1()
        {
            InitializeComponent();

            //Hier werden die angezeigten Werte der Textboxen geladen
            textBox1.Text = vScrollBar1.Value.ToString();
            textBox2.Text = vScrollBar2.Value.ToString();
            textBox3.Text = vScrollBar3.Value.ToString();
            textBox4.Text = vScrollBar4.Value.ToString();
            textBox6.Text = vScrollBar5.Value.ToString();
            textBox7.Text = vScrollBar6.Value.ToString();
            textBox8.Text = vScrollBar7.Value.ToString();
            textBox9.Text = vScrollBar8.Value.ToString();
            textBox10.Text = vScrollBar9.Value.ToString();
            textBox11.Text = vScrollBar10.Value.ToString();
            textBox12.Text = vScrollBar11.Value.ToString();
            textBox13.Text = vScrollBar12.Value.ToString();
            textBox14.Text = vScrollBar13.Value.ToString();
            textBox15.Text = vScrollBar14.Value.ToString();
            textBox16.Text = vScrollBar15.Value.ToString();
            textBox17.Text = vScrollBar16.Value.ToString();
            textBox18.Text = vScrollBar17.Value.ToString();
            textBox19.Text = vScrollBar18.Value.ToString();
            textBox20.Text = vScrollBar19.Value.ToString();
            textBox21.Text = vScrollBar20.Value.ToString();
            textBox22.Text = vScrollBar21.Value.ToString();
            textBox23.Text = vScrollBar22.Value.ToString();
            textBox24.Text = vScrollBar23.Value.ToString();
            textBox25.Text = vScrollBar24.Value.ToString();
            textBox26.Text = vScrollBar25.Value.ToString();
            textBox27.Text = vScrollBar26.Value.ToString();
            textBox28.Text = vScrollBar27.Value.ToString();

            //Hier wechseln wir in den Fullscreen-Modus
        }

        SerialPort serialPort; //Serialport den wir später verwenden - globale Deklaration
        delegate void InvokeLB(string Data);
        SpeechRecognitionEngine recEngine = new SpeechRecognitionEngine();
        

        InvokeLB lbRecievedDelegate;
        Gestures GS = new Gestures();
        int row = 0;
        int step = 0;
        bool run = true;
        bool Speech_rec = false;

        private void bCreateSP_Click(object sender, EventArgs e)
        {

            //Hier erstellen wir unseren Serialport und legen die Einstellungen fest
            serialPort = new SerialPort(cbPort.Text, Convert.ToInt32(cbBaudRate.Text), (Parity)Enum.Parse(typeof(Parity), cbParity.Text), Convert.ToInt16(cbDataBits.Text), (StopBits)Enum.Parse(typeof(StopBits), cbStopbits.Text));
            serialPort.Handshake = (Handshake)Enum.Parse(typeof(Handshake), cbHandshake.Text);
            serialPort.RtsEnable = Boolean.Parse(cbRtsEnable.Text);
            serialPort.DtrEnable = Boolean.Parse(cbDtrEnable.Text);

            if (!serialPort.IsOpen)
            {

                serialPort.Open(); //Serialport öffnen
            }
            lbRecievedDelegate = new InvokeLB(InvokeLBRecieved);
            serialPort.DataReceived += new SerialDataReceivedEventHandler(serialPort_DataReceived); //DataRecieved Event abonnieren
        }

        void serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string RecievedLine = " ";
            while (RecievedLine != "")
            {
                RecievedLine = serialPort.ReadLine();
                Recieved.Invoke(lbRecievedDelegate, new object[] { RecievedLine });
            }

        }
        void InvokeLBRecieved(string Data)
        {
            Recieved.Items.Add(Data);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            if (File.Exists("Gestures.txt"))
            {
                GS = GS.load("Gestures.txt");
            }
            else
            {
                GS.Gestures_names[0] = "Default";
                for (int i = 0; i < 30; i++)
                {
                    GS.Gestures_values[0, 0, i] = 70;
                }
            }
            int Gesture_count = 0;
            for (; GS.Gestures_names[Gesture_count] != null; Gesture_count++) ;
            
            string[] voice_commands = new string[Gesture_count];
            for (int i = 0; i < GS.Gestures_names.Length; i++)
            {
                if(GS.Gestures_names[i] != null)
                {
                    gestures.Items.Add(GS.Gestures_names[i]);
                    voice_commands[i] = GS.Gestures_names[i];
                }
            }

            Choices commands = new Choices();
            commands.Add(voice_commands);
            GrammarBuilder gBuilder = new GrammarBuilder();
            gBuilder.Append(commands);
            Grammar dictationGrammar = new DictationGrammar();

            recEngine.LoadGrammar(dictationGrammar);
            recEngine.SetInputToDefaultAudioDevice();
            recEngine.SpeechRecognized += RecEngine_SpeechRecognized;



            //Hier befüllen wir die Options-ComboBoxen von Serial
            foreach (var item in SerialPort.GetPortNames())
            {
                cbPort.Items.Add(item);
            }
            cbPort.Text = cbPort.Items[0].ToString();

            foreach (var item in Enum.GetNames(typeof(Parity)))
            {
                cbParity.Items.Add(item);
            }
            cbParity.Text = cbParity.Items[0].ToString();

            foreach (var item in Enum.GetNames(typeof(StopBits)))
            {
                cbStopbits.Items.Add(item);
            }
            cbStopbits.Text = cbStopbits.Items[1].ToString();

            cbBaudRate.Items.Add("110");
            cbBaudRate.Items.Add("300");
            cbBaudRate.Items.Add("600");
            cbBaudRate.Items.Add("1200");
            cbBaudRate.Items.Add("2400");
            cbBaudRate.Items.Add("4800");
            cbBaudRate.Items.Add("500000");
            cbBaudRate.Items.Add("14400");
            cbBaudRate.Items.Add("19200");
            cbBaudRate.Items.Add("28800");
            cbBaudRate.Items.Add("38400");
            cbBaudRate.Items.Add("56000");
            cbBaudRate.Items.Add("57600");
            cbBaudRate.Items.Add("9600");
            cbBaudRate.Text = cbBaudRate.Items[6].ToString();

            cbDataBits.Items.Add("5");
            cbDataBits.Items.Add("6");
            cbDataBits.Items.Add("7");
            cbDataBits.Items.Add("8");
            cbDataBits.Items.Add("9");
            cbDataBits.Text = "8";


            foreach (var item in Enum.GetNames(typeof(Handshake)))
            {
                cbHandshake.Items.Add(item);
            }
            cbHandshake.Text = cbHandshake.Items[0].ToString();

            cbDtrEnable.Items.Add("True");
            cbDtrEnable.Items.Add("False");
            cbDtrEnable.Text = "False";

            cbRtsEnable.Items.Add("True");
            cbRtsEnable.Items.Add("False");
            cbRtsEnable.Text = "False";

            RgbMC.Items.Add("RGBR");
            RgbMC.Items.Add("RGBT");
            RgbMC.Text = "RGBR";

            RgbS.Items.Add("Slow");
            RgbS.Items.Add("Medium");
            RgbS.Items.Add("Fast");
            RgbS.Items.Add("10");
            RgbS.Items.Add("5");
            RgbS.Items.Add("1");
            RgbS.Text = "1";

            RgbBr.Text = "255";

            for (int i = 0; i <= 50; i++)
            {
                steps.Items.Add(i);
            }

        }

        void RecEngine_SpeechRecognized(object sender, SpeechRecognizedEventArgs e)
        {
            Recieved_Speech.Text += "\n" + e.Result.Text;
            row = 0;
            for (; row < GS.Gestures_names.Length && GS.Gestures_names[row] != e.Result.Text; row++) ;
            control = new Thread(new ThreadStart(play));
            control.Start();
        }


        void bClearRecieved_Click(object sender, EventArgs e)
        {
            Recieved.Items.Clear();
        }


        void Restart_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }
        int[,] data = new int[50, 7];


        void ScrollBarControl()
        {
            vScrollBar1.Value = GS.Gestures_values[row, step, 1];
            vScrollBar2.Value = GS.Gestures_values[row, step, 2];
            vScrollBar3.Value = GS.Gestures_values[row, step, 3];
            vScrollBar4.Value = GS.Gestures_values[row, step, 4];
            vScrollBar5.Value = GS.Gestures_values[row, step, 5];
            vScrollBar6.Value = GS.Gestures_values[row, step, 6];
            vScrollBar7.Value = GS.Gestures_values[row, step, 7];
            vScrollBar8.Value = GS.Gestures_values[row, step, 8];
            vScrollBar9.Value = GS.Gestures_values[row, step, 9];
            vScrollBar10.Value = GS.Gestures_values[row, step, 10];
            vScrollBar11.Value = GS.Gestures_values[row, step, 11];
            vScrollBar12.Value = GS.Gestures_values[row, step, 12];
            vScrollBar13.Value = GS.Gestures_values[row, step, 13];
            vScrollBar14.Value = GS.Gestures_values[row, step, 14];
            vScrollBar15.Value = GS.Gestures_values[row, step, 15];
            vScrollBar16.Value = GS.Gestures_values[row, step, 16];
            vScrollBar17.Value = GS.Gestures_values[row, step, 17];
            vScrollBar18.Value = GS.Gestures_values[row, step, 18];
            vScrollBar19.Value = GS.Gestures_values[row, step, 19];
            vScrollBar20.Value = GS.Gestures_values[row, step, 20];
            vScrollBar21.Value = GS.Gestures_values[row, step, 21];
            vScrollBar22.Value = GS.Gestures_values[row, step, 22];
            vScrollBar23.Value = GS.Gestures_values[row, step, 23];
            vScrollBar24.Value = GS.Gestures_values[row, step, 24];
            vScrollBar25.Value = GS.Gestures_values[row, step, 25];
            vScrollBar26.Value = GS.Gestures_values[row, step, 26];
            vScrollBar27.Value = GS.Gestures_values[row, step, 27];

            delay.Text = Convert.ToString(GS.Gestures_values[row, step, 28]);

        }


        void play()
        {

            run = true;
            do
            {
                step = 0;
                while (GS.Gestures_values[row, step, 0] == 1 && run == true)
                {

                    this.Invoke(new MethodInvoker(ScrollBarControl));

                    serialPort.WriteLine("Lhb" + GS.Gestures_values[row, step, 1]);
                    serialPort.WriteLine("Lhc" + GS.Gestures_values[row, step, 2]);
                    serialPort.WriteLine("Lhd" + GS.Gestures_values[row, step, 3]);
                    serialPort.WriteLine("Lhe" + GS.Gestures_values[row, step, 4]);
                    serialPort.WriteLine("Lhf" + GS.Gestures_values[row, step, 5]);
                    serialPort.WriteLine("Lhg" + GS.Gestures_values[row, step, 6]);
                    serialPort.WriteLine("Rhb" + GS.Gestures_values[row, step, 7]);
                    serialPort.WriteLine("Rhc" + GS.Gestures_values[row, step, 8]);
                    serialPort.WriteLine("Rhd" + GS.Gestures_values[row, step, 9]);
                    serialPort.WriteLine("Rhe" + GS.Gestures_values[row, step, 10]);
                    serialPort.WriteLine("Rhf" + GS.Gestures_values[row, step, 11]);
                    serialPort.WriteLine("Rhg" + GS.Gestures_values[row, step, 12]);
                    serialPort.WriteLine("Lsd" + GS.Gestures_values[row, step, 13]);
                    serialPort.WriteLine("Lse" + GS.Gestures_values[row, step, 14]);
                    serialPort.WriteLine("Lsf" + GS.Gestures_values[row, step, 15]);
                    serialPort.WriteLine("Lsg" + GS.Gestures_values[row, step, 16]);
                    serialPort.WriteLine("Rsd" + GS.Gestures_values[row, step, 17]);
                    serialPort.WriteLine("Rse" + GS.Gestures_values[row, step, 18]);
                    serialPort.WriteLine("Rsf" + GS.Gestures_values[row, step, 19]);
                    serialPort.WriteLine("Rsg" + GS.Gestures_values[row, step, 20]);
                    serialPort.WriteLine("Mtb" + GS.Gestures_values[row, step, 21]);
                    serialPort.WriteLine("Mtc" + GS.Gestures_values[row, step, 22]);
                    serialPort.WriteLine("Mhb" + GS.Gestures_values[row, step, 23]);
                    serialPort.WriteLine("Mhc" + GS.Gestures_values[row, step, 24]);
                    serialPort.WriteLine("Mhd" + GS.Gestures_values[row, step, 25]);
                    serialPort.WriteLine("Mhe" + GS.Gestures_values[row, step, 26]);
                    serialPort.WriteLine("Mhf" + GS.Gestures_values[row, step, 27]);

                    System.Threading.Thread.Sleep(GS.Gestures_values[row, step, 28]);
                    step++;
                }
            } while (Infinity.Text == "∞" && run == true);
        }

        void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lhb" + vScrollBar1.Value);
            textBox1.Text = vScrollBar1.Value.ToString();
        }


        void vScrollBar2_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lhc" + vScrollBar2.Value);
            textBox2.Text = vScrollBar2.Value.ToString();
        }


        void vScrollBar3_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lhd" + vScrollBar3.Value);
            textBox3.Text = vScrollBar3.Value.ToString();
        }


        void vScrollBar4_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lhe" + vScrollBar4.Value);
            textBox4.Text = vScrollBar4.Value.ToString();
        }


        void vScrollBar5_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lhf" + vScrollBar5.Value);
            textBox6.Text = vScrollBar5.Value.ToString();
        }


        void vScrollBar6_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lhg" + vScrollBar6.Value);
            textBox7.Text = vScrollBar6.Value.ToString();
        }


        void vScrollBar7_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rhb" + vScrollBar7.Value);
            textBox8.Text = vScrollBar7.Value.ToString();
        }


        void vScrollBar8_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rhc" + vScrollBar8.Value);
            textBox9.Text = vScrollBar8.Value.ToString();
        }


        void vScrollBar9_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rhd" + vScrollBar9.Value);
            textBox10.Text = vScrollBar9.Value.ToString();
        }


        void vScrollBar10_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rhe" + vScrollBar10.Value);
            textBox11.Text = vScrollBar10.Value.ToString();
        }


        void vScrollBar11_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rhf" + vScrollBar11.Value);
            textBox12.Text = vScrollBar11.Value.ToString();
        }


        void vScrollBar12_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rhg" + vScrollBar12.Value);
            textBox13.Text = vScrollBar12.Value.ToString();
        }


        void vScrollBar13_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lsd" + vScrollBar13.Value);
            textBox14.Text = vScrollBar13.Value.ToString();
        }


        void vScrollBar14_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lse" + vScrollBar14.Value);
            textBox15.Text = vScrollBar14.Value.ToString();
        }


        void vScrollBar15_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lsf" + vScrollBar15.Value);
            textBox16.Text = vScrollBar15.Value.ToString();
        }


        void vScrollBar16_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Lsg" + vScrollBar16.Value);
            textBox17.Text = vScrollBar16.Value.ToString();
        }


        void vScrollBar17_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rsd" + vScrollBar17.Value);
            textBox18.Text = vScrollBar17.Value.ToString();
        }


        void vScrollBar18_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rse" + vScrollBar18.Value);
            textBox19.Text = vScrollBar18.Value.ToString();
        }


        void vScrollBar19_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rsf" + vScrollBar19.Value);
            textBox20.Text = vScrollBar19.Value.ToString();
        }


        void vScrollBar20_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Rsg" + vScrollBar20.Value);
            textBox21.Text = vScrollBar20.Value.ToString();
        }


        void vScrollBar21_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mtb" + vScrollBar21.Value);
            textBox22.Text = vScrollBar21.Value.ToString();
        }


        void vScrollBar22_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mtc" + vScrollBar22.Value);
            textBox23.Text = vScrollBar22.Value.ToString();
        }


        void vScrollBar23_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mhb" + vScrollBar23.Value);
            textBox24.Text = vScrollBar23.Value.ToString();
        }


        void vScrollBar24_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mhc" + vScrollBar24.Value);
            textBox25.Text = vScrollBar24.Value.ToString();
        }


        void vScrollBar25_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mhd" + vScrollBar25.Value);
            textBox26.Text = vScrollBar25.Value.ToString();
        }


        void vScrollBar26_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mhe" + vScrollBar26.Value);
            textBox27.Text = vScrollBar26.Value.ToString();
        }


        void vScrollBar27_Scroll(object sender, ScrollEventArgs e)
        {
            serialPort.WriteLine("Mhf" + vScrollBar27.Value);
            textBox28.Text = vScrollBar27.Value.ToString();
        }


        void btn_saveGesture_Click(object sender, EventArgs e)
        {
            int row = 0;
            for (; row < GS.Gestures_names.Length && GS.Gestures_names[row] != gestures.Text; row++) ;

            if (GS.Gestures_names[row] != gestures.Text)
                gestures.Text = "Error";
            else
            {
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 0] = 1;

                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 1] = vScrollBar1.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 2] = vScrollBar2.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 3] = vScrollBar3.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 4] = vScrollBar4.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 5] = vScrollBar5.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 6] = vScrollBar6.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 7] = vScrollBar7.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 8] = vScrollBar8.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 9] = vScrollBar9.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 10] = vScrollBar10.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 11] = vScrollBar11.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 12] = vScrollBar12.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 13] = vScrollBar13.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 14] = vScrollBar14.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 15] = vScrollBar15.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 16] = vScrollBar16.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 17] = vScrollBar17.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 18] = vScrollBar18.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 19] = vScrollBar19.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 20] = vScrollBar20.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 21] = vScrollBar21.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 22] = vScrollBar22.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 23] = vScrollBar23.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 24] = vScrollBar24.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 25] = vScrollBar25.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 26] = vScrollBar26.Value;
                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 27] = vScrollBar27.Value;

                GS.Gestures_values[row, Convert.ToInt32(steps.Text), 28] = Convert.ToInt32(delay.Text);
            }

            GS.save("Gestures.txt");
        }


        void btn_createGesture_Click(object sender, EventArgs e)
        {

            int i = 0;
            for (; GS.Gestures_names[i] != null; i++) ;
            GS.Gestures_names[i] = gestureName.Text;
            gestures.Items.Add(GS.Gestures_names[i]);
        }


        void btn_showGesture_Click(object sender, EventArgs e)
        {
            int row = 0;
            for (; row < GS.Gestures_names.Length && GS.Gestures_names[row] != gestures.Text; row++) ;


            vScrollBar1.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 1];
            vScrollBar2.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 2];
            vScrollBar3.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 3];
            vScrollBar4.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 4];
            vScrollBar5.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 5];
            vScrollBar6.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 6];
            vScrollBar7.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 7];
            vScrollBar8.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 8];
            vScrollBar9.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 9];
            vScrollBar10.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 10];
            vScrollBar11.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 11];
            vScrollBar12.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 12];
            vScrollBar13.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 13];
            vScrollBar14.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 14];
            vScrollBar15.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 15];
            vScrollBar16.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 16];
            vScrollBar17.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 17];
            vScrollBar18.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 18];
            vScrollBar19.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 19];
            vScrollBar20.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 20];
            vScrollBar21.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 21];
            vScrollBar22.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 22];
            vScrollBar23.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 23];
            vScrollBar24.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 24];
            vScrollBar25.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 25];
            vScrollBar26.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 26];
            vScrollBar27.Value = GS.Gestures_values[row, Convert.ToInt32(steps.Text), 27];
            serialPort.WriteLine("Lhb" + vScrollBar1.Value);
            serialPort.WriteLine("Lhc" + vScrollBar2.Value);
            serialPort.WriteLine("Lhd" + vScrollBar3.Value);
            serialPort.WriteLine("Lhe" + vScrollBar4.Value);
            serialPort.WriteLine("Lhf" + vScrollBar5.Value);
            serialPort.WriteLine("Lhg" + vScrollBar6.Value);
            serialPort.WriteLine("Rhb" + vScrollBar7.Value);
            serialPort.WriteLine("Rhc" + vScrollBar8.Value);
            serialPort.WriteLine("Rhd" + vScrollBar9.Value);
            serialPort.WriteLine("Rhe" + vScrollBar10.Value);
            serialPort.WriteLine("Rhf" + vScrollBar11.Value);
            serialPort.WriteLine("Rhg" + vScrollBar12.Value);
            serialPort.WriteLine("Lsd" + vScrollBar13.Value);
            serialPort.WriteLine("Lse" + vScrollBar14.Value);
            serialPort.WriteLine("Lsf" + vScrollBar15.Value);
            serialPort.WriteLine("Lsg" + vScrollBar16.Value);
            serialPort.WriteLine("Rsd" + vScrollBar17.Value);
            serialPort.WriteLine("Rse" + vScrollBar18.Value);
            serialPort.WriteLine("Rsf" + vScrollBar19.Value);
            serialPort.WriteLine("Rsg" + vScrollBar20.Value);
            serialPort.WriteLine("Mtb" + vScrollBar21.Value);
            serialPort.WriteLine("Mtc" + vScrollBar22.Value);
            serialPort.WriteLine("Mhb" + vScrollBar23.Value);
            serialPort.WriteLine("Mhc" + vScrollBar24.Value);
            serialPort.WriteLine("Mhd" + vScrollBar25.Value);
            serialPort.WriteLine("Mhe" + vScrollBar26.Value);
            serialPort.WriteLine("Mhf" + vScrollBar27.Value);

            delay.Text = Convert.ToString(GS.Gestures_values[row, Convert.ToInt32(steps.Text), 28]);

        }


        void btn_deleteGesture_Click(object sender, EventArgs e)
        {
            int row = 0;
            for (; row < GS.Gestures_names.Length && GS.Gestures_names[row] != gestures.Text; row++) ;
            GS.Gestures_values[row, Convert.ToInt32(steps.Text), 0] = 0;
        }


        void btn_playGesture_Click(object sender, EventArgs e)
        {
            row = 0;
            for (; row < GS.Gestures_names.Length && GS.Gestures_names[row] != gestures.Text; row++) ;
            control = new Thread(new ThreadStart(play));
            control.Start();
        }


        void btn_stopGesture_Click(object sender, EventArgs e)
        {
            run = false;
        }


        void Infinity_Click(object sender, EventArgs e)
        {
            if (Infinity.Text == "∞")
            {
                Infinity.Text = "1";
                Infinity.Font = new Font("Microsoft Sans Serif", 8);
            }
            else
            {
                Infinity.Text = "∞";
                Infinity.Font = new Font("Arial", 14);
            }
        }


        void btn_setdefault_Click(object sender, EventArgs e)
        {

            vScrollBar1.Value = GS.Gestures_values[0, 0, 1];
            vScrollBar2.Value = GS.Gestures_values[0, 0, 2];
            vScrollBar3.Value = GS.Gestures_values[0, 0, 3];
            vScrollBar4.Value = GS.Gestures_values[0, 0, 4];
            vScrollBar5.Value = GS.Gestures_values[0, 0, 5];
            vScrollBar6.Value = GS.Gestures_values[0, 0, 6];
            vScrollBar7.Value = GS.Gestures_values[0, 0, 7];
            vScrollBar8.Value = GS.Gestures_values[0, 0, 8];
            vScrollBar9.Value = GS.Gestures_values[0, 0, 9];
            vScrollBar10.Value = GS.Gestures_values[0, 0, 10];
            vScrollBar11.Value = GS.Gestures_values[0, 0, 11];
            vScrollBar12.Value = GS.Gestures_values[0, 0, 12];
            vScrollBar13.Value = GS.Gestures_values[0, 0, 13];
            vScrollBar14.Value = GS.Gestures_values[0, 0, 14];
            vScrollBar15.Value = GS.Gestures_values[0, 0, 15];
            vScrollBar16.Value = GS.Gestures_values[0, 0, 16];
            vScrollBar17.Value = GS.Gestures_values[0, 0, 17];
            vScrollBar18.Value = GS.Gestures_values[0, 0, 18];
            vScrollBar19.Value = GS.Gestures_values[0, 0, 19];
            vScrollBar20.Value = GS.Gestures_values[0, 0, 20];
            vScrollBar21.Value = GS.Gestures_values[0, 0, 21];
            vScrollBar22.Value = GS.Gestures_values[0, 0, 22];
            vScrollBar23.Value = GS.Gestures_values[0, 0, 23];
            vScrollBar24.Value = GS.Gestures_values[0, 0, 24];
            vScrollBar25.Value = GS.Gestures_values[0, 0, 25];
            vScrollBar26.Value = GS.Gestures_values[0, 0, 26];
            vScrollBar27.Value = GS.Gestures_values[0, 0, 27];

            serialPort.WriteLine("Lhb" + vScrollBar1.Value);
            serialPort.WriteLine("Lhc" + vScrollBar2.Value);
            serialPort.WriteLine("Lhd" + vScrollBar3.Value);
            serialPort.WriteLine("Lhe" + vScrollBar4.Value);
            serialPort.WriteLine("Lhf" + vScrollBar5.Value);
            serialPort.WriteLine("Lhg" + vScrollBar6.Value);
            serialPort.WriteLine("Rhb" + vScrollBar7.Value);
            serialPort.WriteLine("Rhc" + vScrollBar8.Value);
            serialPort.WriteLine("Rhd" + vScrollBar9.Value);
            serialPort.WriteLine("Rhe" + vScrollBar10.Value);
            serialPort.WriteLine("Rhf" + vScrollBar11.Value);
            serialPort.WriteLine("Rhg" + vScrollBar12.Value);
            serialPort.WriteLine("Lsd" + vScrollBar13.Value);
            serialPort.WriteLine("Lse" + vScrollBar14.Value);
            serialPort.WriteLine("Lsf" + vScrollBar15.Value);
            serialPort.WriteLine("Lsg" + vScrollBar16.Value);
            serialPort.WriteLine("Rsd" + vScrollBar17.Value);
            serialPort.WriteLine("Rse" + vScrollBar18.Value);
            serialPort.WriteLine("Rsf" + vScrollBar19.Value);
            serialPort.WriteLine("Rsg" + vScrollBar20.Value);
            serialPort.WriteLine("Mtb" + vScrollBar21.Value);
            serialPort.WriteLine("Mtc" + vScrollBar22.Value);
            serialPort.WriteLine("Mhb" + vScrollBar23.Value);
            serialPort.WriteLine("Mhc" + vScrollBar24.Value);
            serialPort.WriteLine("Mhd" + vScrollBar25.Value);
            serialPort.WriteLine("Mhe" + vScrollBar26.Value);
            serialPort.WriteLine("Mhf" + vScrollBar27.Value);

            textBox1.Text = vScrollBar1.Value.ToString();
            textBox2.Text = vScrollBar2.Value.ToString();
            textBox3.Text = vScrollBar3.Value.ToString();
            textBox4.Text = vScrollBar4.Value.ToString();
            textBox6.Text = vScrollBar5.Value.ToString();
            textBox7.Text = vScrollBar6.Value.ToString();
            textBox8.Text = vScrollBar7.Value.ToString();
            textBox9.Text = vScrollBar8.Value.ToString();
            textBox10.Text = vScrollBar9.Value.ToString();
            textBox11.Text = vScrollBar10.Value.ToString();
            textBox12.Text = vScrollBar11.Value.ToString();
            textBox13.Text = vScrollBar12.Value.ToString();
            textBox14.Text = vScrollBar13.Value.ToString();
            textBox15.Text = vScrollBar14.Value.ToString();
            textBox16.Text = vScrollBar15.Value.ToString();
            textBox17.Text = vScrollBar16.Value.ToString();
            textBox18.Text = vScrollBar17.Value.ToString();
            textBox19.Text = vScrollBar18.Value.ToString();
            textBox20.Text = vScrollBar19.Value.ToString();
            textBox21.Text = vScrollBar20.Value.ToString();
            textBox22.Text = vScrollBar21.Value.ToString();
            textBox23.Text = vScrollBar22.Value.ToString();
            textBox24.Text = vScrollBar23.Value.ToString();
            textBox25.Text = vScrollBar24.Value.ToString();
            textBox26.Text = vScrollBar25.Value.ToString();
            textBox27.Text = vScrollBar26.Value.ToString();
            textBox28.Text = vScrollBar27.Value.ToString();
        }


        void btn_Speech_Click(object sender, EventArgs e)
        {
            if (Speech_rec == false)
            {
                Speech_rec = true;
                recEngine.RecognizeAsync(RecognizeMode.Multiple);
                btn_Speech.Text = "stop Speech Recognition";
            }
            else
            {
                Speech_rec = false;
                recEngine.RecognizeAsyncStop();
                btn_Speech.Text = "start Speech Recognition";
            }
        }


        void label23_Click(object sender, EventArgs e)
        {

        }


        void textBox1_TextChanged(object sender, EventArgs e)
        {
            vScrollBar1.Value = int.Parse(textBox1.Text);
        }


        void textBox2_TextChanged(object sender, EventArgs e)
        {
            vScrollBar2.Value = int.Parse(textBox2.Text);
        }


        void textBox3_TextChanged(object sender, EventArgs e)
        {
            vScrollBar3.Value = int.Parse(textBox3.Text);
        }


        void textBox4_TextChanged(object sender, EventArgs e)
        {
            vScrollBar4.Value = int.Parse(textBox4.Text);
        }


        void textBox6_TextChanged(object sender, EventArgs e)
        {
            vScrollBar5.Value = int.Parse(textBox6.Text);
        }


        void textBox7_TextChanged(object sender, EventArgs e)
        {
            vScrollBar6.Value = int.Parse(textBox7.Text);
        }


        void textBox8_TextChanged(object sender, EventArgs e)
        {
            vScrollBar7.Value = int.Parse(textBox8.Text);
        }


        void textBox9_TextChanged(object sender, EventArgs e)
        {
            vScrollBar8.Value = int.Parse(textBox9.Text);
        }


        void textBox10_TextChanged(object sender, EventArgs e)
        {
            vScrollBar9.Value = int.Parse(textBox10.Text);
        }


        void textBox11_TextChanged(object sender, EventArgs e)
        {
            vScrollBar10.Value = int.Parse(textBox11.Text);
        }


        void textBox12_TextChanged(object sender, EventArgs e)
        {
            vScrollBar11.Value = int.Parse(textBox12.Text);
        }


        void textBox13_TextChanged(object sender, EventArgs e)
        {
            vScrollBar12.Value = int.Parse(textBox13.Text);
        }


        void textBox14_TextChanged(object sender, EventArgs e)
        {
            vScrollBar13.Value = int.Parse(textBox14.Text);
        }


        void textBox15_TextChanged(object sender, EventArgs e)
        {
            vScrollBar14.Value = int.Parse(textBox15.Text);
        }


        void textBox16_TextChanged(object sender, EventArgs e)
        {
            vScrollBar15.Value = int.Parse(textBox16.Text);
        }


        void textBox17_TextChanged(object sender, EventArgs e)
        {
            vScrollBar16.Value = int.Parse(textBox17.Text);
        }


        void textBox18_TextChanged(object sender, EventArgs e)
        {
            vScrollBar17.Value = int.Parse(textBox18.Text);
        }


        void textBox19_TextChanged(object sender, EventArgs e)
        {
            vScrollBar18.Value = int.Parse(textBox19.Text);
        }


        void textBox20_TextChanged(object sender, EventArgs e)
        {
            vScrollBar19.Value = int.Parse(textBox20.Text);
        }


        void textBox21_TextChanged(object sender, EventArgs e)
        {
            vScrollBar20.Value = int.Parse(textBox21.Text);
        }


        void textBox22_TextChanged(object sender, EventArgs e)
        {
            vScrollBar21.Value = int.Parse(textBox22.Text);
        }


        void textBox23_TextChanged(object sender, EventArgs e)
        {
            vScrollBar22.Value = int.Parse(textBox23.Text);
        }


        void textBox24_TextChanged(object sender, EventArgs e)
        {
            vScrollBar23.Value = int.Parse(textBox24.Text);
        }


        void textBox25_TextChanged(object sender, EventArgs e)
        {
            vScrollBar24.Value = int.Parse(textBox25.Text);
        }


        void textBox26_TextChanged(object sender, EventArgs e)
        {
            vScrollBar25.Value = int.Parse(textBox26.Text);
        }


        void textBox27_TextChanged(object sender, EventArgs e)
        {
            vScrollBar26.Value = int.Parse(textBox27.Text);
        }


        void textBox28_TextChanged(object sender, EventArgs e)
        {
            vScrollBar27.Value = int.Parse(textBox28.Text);
        }

        void button1_Click(object sender, EventArgs e)
        {
            serialPort.WriteLine($"RGBE{RgbRep.Text}");
            serialPort.WriteLine($"RGBB{RgbBr.Text}");
            serialPort.WriteLine($"RGBS{RgbS.Text}");
            serialPort.WriteLine($"{RgbMC.Text}");
        }

        private void Restart_Click_1(object sender, EventArgs e)
        {

        }

        private void RgbBr_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
