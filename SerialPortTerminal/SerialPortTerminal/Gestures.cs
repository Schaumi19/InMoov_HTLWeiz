using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace SerialPortTerminal
{
    [Serializable]
    public class Gestures
    {
        public string[] Gestures_names { get; set; } = new string[50];
        public int[,,] Gestures_values { get; set; } = new int[50, 50, 30];
        

        public void save(string path)
        {
            
            System.IO.FileStream FS = new System.IO.FileStream(path, System.IO.FileMode.Create);
            BinaryFormatter BF = new BinaryFormatter();
            BF.Serialize(FS, this);
            FS.Dispose();
        }

        public Gestures load(string path)
        {
            Gestures GS = new Gestures();

            System.IO.FileStream FS = new System.IO.FileStream(path, System.IO.FileMode.Open);
            BinaryFormatter BF = new BinaryFormatter();

            GS = (Gestures)BF.Deserialize(FS);

            return GS;
        }
    }
}
