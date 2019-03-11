# HttpWebRequest 的用法
## Post请求
```C#
string Url = "http://xxxxxxx";
HttpWebRequest request = (HttpWebRequest)WebRequest.Create(Url);
request.Method = "POST"; //请求方式
request.ContentType = "application/x-www-form-urlencoded";//请求类型
request.Headers["xxxxx"] = xxx;//请求头
//这里的意思获取数据data的长度，因为是以流的形式发送数据
request.ContentLength = Encoding.UTF8.GetByteCount(data);
Stream requestStream = request.GetRequestStream();//创建流对象来写入Requst请求的参数流内涵url和key值等
StreamWriter streamWriter = new StreamWriter(requestStream, Encoding.GetEncoding("UTF-8");
streamWriter.Write(data);//这里才是真正发送数据的地方
streamWriter.Close();//关闭流
---------------//至此发送数据完成
//接受响应
HttpWebResponse response = request.GetResponse() as HttpWebResponse;
Stream responseStream = response.GetResponseStream();
using (StreamReader reader = new StreamReader(responseStream, Encoding.GetEncoding("UTF-8")))
{
    resData = reader.ReadToEnd();//服务器返回的数据
}
responseStream.Close();
//如返回结果为json，则转为json对象
JObject jo = (JObject)JsonConvert.DeserializeObject(resData);
string xxx = jo["字段名"].toString()
```
## Get请求
```C#
string Url = "http://xxxxxxx?参数名=xxx&参数名=xxx";
HttpWebRequest request = (HttpWebRequest)WebRequest.Create(Url);
request.Method = "GET";
request.ContentType = "text/html;charset=UTF-8";
HttpWebResponse response = (HttpWebResponse)request.GetResponse();
Stream responseStream = response.GetResponseStream();
using (StreamReader reader = new StreamReader(responseStream, Encoding.GetEncoding("UTF-8")))
{
    resData = reader.ReadToEnd();//服务器返回的数据
}
responseStream.close()
//如返回结果为json，则转为json对象
JObject jo = (JObject)JsonConvert.DeserializeObject(resData);
string xxx = jo["字段名"].toString()
```