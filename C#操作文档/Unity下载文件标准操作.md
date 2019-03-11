# Unity5.4后将放弃WWW请求改为UnityWebRequest
## 正常操作
```C#
IEnumerator downLoad(){
    UnityWebRequest request = UnityWebRequest.Get("http://example.com");
    yield return request.Send();

    if (request.isError) {
        Debug.Log(request.error);
    } else {
        if (request.responseCode == 200) {
            //返回的文本
            string text = request.downloadHandler.text;
            //返回的数据
            byte [] results = request.downloadHandler.data;
        }
    }
}
```
## 下载AssetBundel包
```C#
IEnumerator GetAssetBundle() {
    UnityWebRequest www = UnityWebRequest.GetAssetBundle("http://www.my-server.com/myData.unity3d");
    yield return www.SendWebRequest();

    if(www.isNetworkError || www.isHttpError) {
        Debug.Log(www.error);
    }
    else {
        AssetBundle bundle = DownloadHandlerAssetBundle.GetContent(www);
        //加载预制体
        GameObject obj = bundle.LoadAsset<GameObject>(PrefabName);
    }
}
```